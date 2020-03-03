#ifndef OOP_SAVE_COMMAND_H
#define OOP_SAVE_COMMAND_H

#include "save_load_command.h"
#include <field/field.h>
#include <fstream>
#include <memory>
#include <objects/base/base.h>
#include <objects/units/mages/mage.h>

namespace save_load
{
    class save_command : public save_load_command
    {
    private:
        std::map<game::units::unit*, int> units_ids;

        std::unique_ptr<std::ofstream> fstream;

        void save_field(std::shared_ptr<game::field::field::field_memento> _field_memento, std::vector<uint8_t>& _res);

        void save_cells(std::vector<std::vector<std::shared_ptr<game::field::cell::cell_memento>>>&& _cell_mementos,
                        std::vector<uint8_t>& _res);

        static void
        save_object(std::shared_ptr<game::object::object_memento> _object_memento, std::vector<uint8_t>& _res);

        void save_base(std::shared_ptr<game::base::base_memento> _base_memento, std::vector<uint8_t>& _res);

        void save_unit(std::shared_ptr<game::units::unit::unit_memento> _unit_memento, std::vector<uint8_t>& _res);

        void
        save_mage(std::shared_ptr<game::units::mages::mage::mage_memento> _unit_memento, std::vector<uint8_t>& _res);

        void save_bases_mappings(std::vector<uint8_t>& _res);

    public:
        save_command(std::shared_ptr<game::field::field> _field, const std::string& file_name);

        void operator()() override;

        ~save_command();
    };
}

#endif //OOP_SAVE_COMMAND_H
