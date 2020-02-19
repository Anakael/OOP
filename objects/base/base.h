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

namespace game
{
    class base : public object, public subscriber
    {
    private:
        std::optional<unit_enum> selected_unit;
        std::unique_ptr<game::units::unit_factory> factory;
        std::vector<std::reference_wrapper<units::unit>> units;
        int max_units_count;
    public:
        base(int _max_units_count);

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
    };
}

#endif //LAB1_BASE_H
