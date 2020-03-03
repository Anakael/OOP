#include "load_command.h"
#include <fstream>
#include <utility>
#include <field/field.h>
#include <objects/attributes/attack_attribute.h>
#include <objects/units/mages/priest/priest.h>
#include <objects/units/mages/sourcerer/soucerer.h>
#include <objects/units/warriors/knight/knight.h>
#include <objects/units/warriors/footman/footman.h>
#include <objects/units/shooters/archer/archer.h>
#include <objects/units/shooters/rifleman/rifleman.h>


namespace save_load
{
    load_command::load_command(std::shared_ptr<game::field::field> _field, const std::string& _file_name)
            : save_load_command(std::move(_field), _file_name),
              fstream(std::make_unique<std::ifstream>(_file_name, std::ios_base::binary))
    {
    }

    void load_command::operator()()
    {
        load_field();
        bases.clear();
        ids_units.clear();
    }

    void load_command::load_field()
    {
        auto crc_code = CRC32_count(file_name);
        unsigned int saved_crc_code;
        fstream->read((char*) &saved_crc_code, sizeof(saved_crc_code));
        if (crc_code != saved_crc_code)
        {
            std::cout << "FILE CORRUPTED!" << std::endl;
        }
        size_t length, width;
        int max, curr;
        fstream->read((char*) &length, sizeof(length));
        fstream->read((char*) &width, sizeof(width));
        fstream->read((char*) &max, sizeof(max));
        fstream->read((char*) &curr, sizeof(curr));
        auto field_memento = std::make_shared<game::field::field::field_memento>(length, width, max, curr,
                                                                                 load_cells(length, width));
        field = std::make_shared<game::field::field>(length, width, max);
        field->restore(field_memento);
        init_bases_and_units_ids(length, width);
        load_bases_mappings();

    }

    load_command::~load_command()
    {
        fstream->close();
    }

    std::vector<std::vector<std::shared_ptr<game::field::cell::cell_memento>>>
    load_command::load_cells(size_t _length, size_t _width)
    {
        std::vector<std::vector<std::shared_ptr<game::field::cell::cell_memento>>> ret_mementos;

        for (int i = 0; i < _length; ++i)
        {
            ret_mementos.emplace_back();
            for (int j = 0; j < _width; ++j)
            {
                std::type_index landscape_type = typeid(game::field::landscape::plain);
                fstream->read((char*) &landscape_type, sizeof(landscape_type));
                ret_mementos[i].emplace_back(
                        std::make_shared<game::field::cell::cell_memento>(landscape_type, load_object()));
            }
        }

        return ret_mementos;
    }

    std::shared_ptr<game::object::object_memento> load_command::load_object()
    {
        std::type_index object_type = typeid(nullptr);
        fstream->read((char*) &object_type, sizeof(object_type));
        if (object_type == typeid(nullptr))
        {
            return nullptr;
        }

        int health, max_health, armor;
        fstream->read((char*) &health, sizeof(health));
        fstream->read((char*) &max_health, sizeof(max_health));
        fstream->read((char*) &armor, sizeof(armor));
        using game::attributes::protected_attribute;
        using game::attributes::base_attribute;
        auto health_attrib = protected_attribute(health, max_health);
        auto armor_attrib = base_attribute(armor);

        using game::units::warriors::footman;
        using game::units::warriors::knight;
        using game::units::shooters::archer;
        using game::units::shooters::rifleman;
        using game::units::mages::priest;
        using game::units::mages::soucerer;

        if (object_type == typeid(game::base))
        {
            return load_base(health_attrib, armor);
        }
        else if (object_type == typeid(footman) || object_type == typeid(knight) || object_type == typeid(archer) ||
                 object_type == typeid(rifleman) || object_type == typeid(priest) || object_type == typeid(soucerer))
        {
            return load_unit(health_attrib, armor_attrib, object_type);
        }
        return std::make_shared<game::object::object_memento>(health_attrib, armor_attrib, object_type);
    }

    std::shared_ptr<game::base::base_memento>
    load_command::load_base(const game::attributes::protected_attribute& _health,
                            const game::attributes::base_attribute& armor)
    {
        int max_units;
        fstream->read((char*) &max_units, sizeof(max_units));
        return std::make_shared<game::base::base_memento>(_health, armor, typeid(game::base), max_units);
    }

    std::shared_ptr<game::units::unit::unit_memento>
    load_command::load_unit(const game::attributes::protected_attribute& _health,
                            const game::attributes::base_attribute& armor,
                            std::type_index _unit_type)
    {
        int attack_value;
        int attack_range;
        fstream->read((char*) &attack_value, sizeof(attack_value));
        fstream->read((char*) &attack_range, sizeof(attack_range));
        auto attack_attrib = game::attributes::attack_attribute(attack_value,
                                                                attack_range);
        using game::units::mages::priest;
        using game::units::mages::soucerer;
        if (_unit_type == typeid(priest) || _unit_type == typeid(soucerer))
        {
            return load_mage(_health, armor, _unit_type, attack_attrib);
        }

        return std::make_shared<game::units::unit::unit_memento>(_health, armor, _unit_type, attack_attrib);
    }

    std::shared_ptr<game::units::mages::mage::mage_memento>
    load_command::load_mage(const game::attributes::protected_attribute& _health,
                            const game::attributes::base_attribute& _armor,
                            std::type_index _unit_type,
                            const game::attributes::attack_attribute& _attack)
    {
        int mana_value;
        int mana_max_value;
        fstream->read((char*) &mana_value, sizeof(mana_value));
        fstream->read((char*) &mana_max_value, sizeof(mana_max_value));

        return std::make_shared<game::units::mages::mage::mage_memento>(_health, _armor, _unit_type, _attack,
                                                                        game::attributes::protected_attribute(
                                                                                mana_value,
                                                                                mana_max_value));
    }

    void load_command::init_bases_and_units_ids(size_t _length, size_t _width)
    {
        for (int i = 0; i < _length; ++i)
        {
            for (int j = 0; j < _width; ++j)
            {
                auto obj = field->get({i, j}).get_object();
                if (auto base$ = std::dynamic_pointer_cast<game::base>(obj))
                {
                    bases.emplace_back(static_cast<game::base&>(*field->get({i, j}).get_object()));
                }
                else if (auto unit$ = std::dynamic_pointer_cast<game::units::unit>(obj))
                {
                    ids_units.emplace_back(static_cast<game::units::unit&>(*field->get({i, j}).get_object()));
                }
            }
        }
    }

    void load_command::load_bases_mappings()
    {
        for (auto& base : bases)
        {
            int units_count;
            fstream->read((char*) &units_count, sizeof(units_count));
            std::vector<std::reference_wrapper<game::units::unit>> units;
            for (int i = 0; i < units_count; ++i)
            {
                int id;
                fstream->read((char*) &id, sizeof(id));
                units.emplace_back(ids_units[id - 1]);
            }
            base.get().set_units_ids_from_mapping(units);
        }
    }
}