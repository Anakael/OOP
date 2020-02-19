#ifndef OOP_UNIT_TREE_LEAF_H
#define OOP_UNIT_TREE_LEAF_H

#include "unit_tree_component.h"
#include <objects/units/unit.h>

namespace game::views
{
    class unit_tree_leaf : public unit_tree_component
    {
    private:
        units::unit& unit;
    public:
        unit_tree_leaf(units::unit& _unit);

        units::unit& get_unit() const
        { return unit; }
    };
}


#endif //OOP_UNIT_TREE_LEAF_H
