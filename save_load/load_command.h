#ifndef OOP_LOAD_COMMAND_H
#define OOP_LOAD_COMMAND_H

#include "save_load_command.h"
#include <field/cell.h>
#include <memory>
#include <objects/attributes/protected_attribute.h>
#include <objects/units/mages/mage.h>

namespace save_load
{
    class load_command : public save_load_command
    {
    private:
        std::unique_ptr<std::ifstream> fstream;

        std::vector<std::reference_wrapper<game::units::unit>> ids_units;

        void load_field();

        std::vector<std::vector<std::shared_ptr<game::field::cell::cell_memento>>>
        load_cells(size_t _length, size_t _width);

        std::shared_ptr<game::object::object_memento> load_object();

        std::shared_ptr<game::base::base_memento>
        load_base(const game::attributes::protected_attribute& _health, const game::attributes::base_attribute& _armor);

        std::shared_ptr<game::units::unit::unit_memento>
        load_unit(const game::attributes::protected_attribute& _health, const game::attributes::base_attribute& _armor,
                  std::type_index _unit_type);

        std::shared_ptr<game::units::mages::mage::mage_memento>
        load_mage(const game::attributes::protected_attribute& _health, const game::attributes::base_attribute& _armor,
                  std::type_index _unit_type,
                  const game::attributes::attack_attribute& _attack);

        void init_bases_and_units_ids(size_t _length, size_t _width);

        void load_bases_mappings();

    public:
        load_command(std::shared_ptr<game::field::field> _field, const std::string& _file_name);

        void operator()() override;

        ~load_command();
    };
}

#endif //OOP_LOAD_COMMAND_H
