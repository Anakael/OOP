#ifndef LAB1_BASE_H
#define LAB1_BASE_H

#include <objects/object.h>
#include <optional>
#include <objects/units/unit_factory.h>
#include <observer/subscriber.h>
#include <common/coordinates.h>
#include <mediator/component.h>
#include "views/unit_tree_component.h"
#include <vector>
#include <memory>
#include <save_load/originator.h>

namespace save_load
{
    class save_command;
}

namespace game
{
    class base : public object, public subscriber
    {
    private:
        std::optional<unit_enum> selected_unit;
        std::unique_ptr<game::units::unit_factory> factory;
        std::vector<std::reference_wrapper<units::unit>> units;
        int max_units_count = 0;
    public:
        base() = default;

        explicit base(int _max_units_count);

        void select_unit_to_create(unit_enum _unit_type)
        { selected_unit = _unit_type; }

        int get_max_units_count() const
        { return max_units_count; }

        int get_units_count() const
        { return units.size(); }

        std::optional<unit_enum> get_selected_unit() const
        { return selected_unit; }

        std::shared_ptr<views::unit_tree_component> get_tree_view() const;

        std::shared_ptr<game::units::unit> create_unit(common::coordinates _to);

        void update(const units::unit& _unit) override;

        std::vector<int> get_units_ids_from_mapping(std::map<game::units::unit*, int>& _mapping);

        void set_units_ids_from_mapping(std::vector<std::reference_wrapper<units::unit>>& _units)
        { units = _units; }

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento>) override;

        class base_memento : public object_memento
        {
        private:
            friend class save_load::save_command;

            friend class base;

            int max_units;
        public:
            base_memento(game::attributes::protected_attribute _health, game::attributes::base_attribute _armor,
                         std::type_index _object_type,
                         int _max_units)
                    : object_memento(std::move(_health), std::move(_armor), _object_type), max_units(_max_units)
            {}
        };
    };
}

#endif //LAB1_BASE_H
