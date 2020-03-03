#include "save_command.h"
#include <cstring>
#include <utility>
#include <objects/base/base.h>

namespace save_load
{
    save_command::save_command(std::shared_ptr<game::field::field> _field, const std::string& _file_name)
            : save_load_command(std::move(_field), _file_name),
              fstream(std::make_unique<std::ofstream>(_file_name, std::ios_base::binary))
    {
    }

    template<typename T>
    void to_vec(T val, std::vector<uint8_t>& vec)
    {
        uint8_t arr[sizeof(T)];
        std::memcpy(arr, &val, sizeof(T));
        for (auto& v : arr)
        {
            vec.push_back(v);
        }
    }

    void save_command::operator()()
    {
        std::vector<uint8_t> res;
        save_field(std::static_pointer_cast<game::field::field::field_memento>(field->save()), res);
        fstream->seekp(sizeof(unsigned int), fstream->beg);
        fstream->write((char*) &res[0], res.size());
        auto crc_code = CRC32_function(res.data(), res.size());
        fstream->seekp(0, fstream->beg);
        fstream->write((char*) &crc_code, sizeof(crc_code));
        bases.clear();
        units_ids.clear();
    }

    save_command::~save_command()
    {
        fstream->close();
    }

    void save_command::save_cells(
            std::vector<std::vector<std::shared_ptr<game::field::cell::cell_memento>>>&& _cell_mementos,
            std::vector<uint8_t>& _res)
    {
        for (int i = 0; i < _cell_mementos.size(); ++i)
        {
            for (int j = 0; j < _cell_mementos[i].size(); ++j)
            {
                auto& cell_memento = _cell_mementos[i][j];
                to_vec(cell_memento->landscape_type, _res);
                auto obj_momento = cell_memento->object;

                if (!obj_momento)
                {
                    to_vec(std::type_index(typeid(nullptr)), _res);
                }
                else
                {
                    save_object(obj_momento, _res);
                    if (cell_memento->object->object_type == typeid(game::base))
                    {
                        bases.emplace_back(static_cast<game::base&>(*field->get({i, j}).get_object()));
                        save_base(std::static_pointer_cast<game::base::base_memento>(obj_momento), _res);
                    }
                    else if (auto unit_momento$ = std::dynamic_pointer_cast<game::units::unit::unit_memento>(
                            obj_momento))
                    {
                        units_ids[static_cast<game::units::unit*>(&*field->get({i, j}).get_object())] =
                                units_ids.size() + 1;
                        save_unit(unit_momento$, _res);
                    }
                }
            }
        }
        save_bases_mappings(_res);
    }

    void save_command::save_field(std::shared_ptr<game::field::field::field_memento> _field_memento,
                                  std::vector<uint8_t>& _res)
    {
        to_vec(_field_memento->length, _res);
        to_vec(_field_memento->width, _res);
        to_vec(_field_memento->max_objects_count, _res);
        to_vec(_field_memento->count_objects, _res);
        save_cells(std::move(_field_memento->cells_mementos), _res);
    }

    void
    save_command::save_object(std::shared_ptr<game::object::object_memento> _object_memento, std::vector<uint8_t>& _res)
    {
        to_vec(_object_memento->object_type, _res);
        auto health_momento = _object_memento->health;
        to_vec(health_momento.get_value(), _res);
        to_vec(health_momento.get_max_value(), _res);
        to_vec(_object_memento->armor.get_value(), _res);
    }

    void save_command::save_base(std::shared_ptr<game::base::base_memento> _base_memento, std::vector<uint8_t>& _res)
    {
        to_vec(_base_memento->max_units, _res);
    }

    void
    save_command::save_unit(std::shared_ptr<game::units::unit::unit_memento> _unit_memento, std::vector<uint8_t>& _res)
    {
        auto attack = _unit_memento->attack;
        to_vec(attack.get_value(), _res);
        to_vec(attack.get_attack_range(), _res);
        if (auto mage_momento$ = std::dynamic_pointer_cast<game::units::mages::mage::mage_memento>(_unit_memento))
        {
            save_mage(mage_momento$, _res);
        }
    }

    void save_command::save_mage(std::shared_ptr<game::units::mages::mage::mage_memento> _mage_memento,
                                 std::vector<uint8_t>& _res)
    {
        auto mana = _mage_memento->mana;
        to_vec(mana.get_value(), _res);
        to_vec(mana.get_max_value(), _res);
    }

    void save_command::save_bases_mappings(std::vector<uint8_t>& _res)
    {
        for (auto& base : bases)
        {
            auto units = base.get().get_units_ids_from_mapping(units_ids);
            to_vec(units.size(), _res);
            for (auto& unit : units)
            {
                to_vec(unit, _res);
            }
        }
    }
}

