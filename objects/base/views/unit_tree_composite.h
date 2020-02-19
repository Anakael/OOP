#ifndef OOP_UNIT_TREE_COMPOSITE_H
#define OOP_UNIT_TREE_COMPOSITE_H

#include "unit_tree_component.h"
#include <string>
#include <objects/units/warriors/warrior.h>
#include <objects/units/shooters/shooter.h>
#include "unit_tree_leaf.h"
#include <objects/units/mages/mage.h>
#include <typeinfo>
#include <map>
#include <memory>
#include <typeindex>

namespace game::views
{
    class unit_tree_composite : public unit_tree_component
    {
    private:
        std::map<std::type_index, std::vector<std::shared_ptr<unit_tree_component>>> children;
        void inner_add(units::unit& _unit);

    public:
        void add(units::unit& _unit);

        void add(units::warriors::warrior& _warrior);

        void add(units::shooters::shooter& _shooter);

        void add(units::mages::mage& _mage);

        std::map<std::type_index, std::vector<std::shared_ptr<unit_tree_component>>> get_children() const
        { return children; }
    };
}


#endif //OOP_UNIT_TREE_COMPOSITE_H
