#include "unit_tree_composite.h"

namespace game::views
{
    void unit_tree_composite::inner_add(units::unit& _unit)
    {
        add(_unit);
    }

    void unit_tree_composite::add(units::warriors::warrior& _warrior)
    {
        auto vec = children.at(typeid(units::warriors::warrior));
        if (vec.empty())
        {
            auto composite = std::make_shared<unit_tree_composite>();
            children[typeid(units::warriors::warrior)].push_back(composite);
        }
        auto& composite = dynamic_cast<unit_tree_composite&>(*vec[0]);
        composite.inner_add(_warrior);
    }

    void unit_tree_composite::add(units::shooters::shooter& _shooter)
    {
        auto vec = children.at(typeid(units::shooters::shooter));
        if (vec.empty())
        {
            auto composite = std::make_shared<unit_tree_composite>();
            children[typeid(units::warriors::warrior)].push_back(composite);
        }
        auto& composite = dynamic_cast<unit_tree_composite&>(*vec[0]);
        composite.inner_add(_shooter);
    }

    void unit_tree_composite::add(units::mages::mage& _mage)
    {
        auto it = children.find(typeid(units::mages::mage));
        if (children.find(typeid(units::mages::mage)) == children.end())
        {
            auto composite = std::make_shared<unit_tree_composite>();
            it = children.emplace(typeid(units::mages::mage),
                                  std::vector<std::shared_ptr<unit_tree_component>>{composite}).first;
        }
        auto& composite = dynamic_cast<unit_tree_composite&>(*it->second[0]);
        composite.inner_add(_mage);
    }

    void unit_tree_composite::add(units::unit& _unit)
    {
        children[typeid(_unit)].push_back(std::make_shared<unit_tree_leaf>(_unit));
    }
}


