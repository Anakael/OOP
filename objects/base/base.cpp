#include "base.h"
#include <iostream>
#include <commands/create_object_command.h>
#include <logger/logger_proxy.h>
#include "views/unit_tree_composite.h"
#include "balance.h"

namespace
{
    template<typename T>
    bool try_cast_and_call(std::shared_ptr<game::views::unit_tree_composite> component, game::units::unit& obj)
    {
        try
        {
            auto& cast = dynamic_cast<T&>(obj);
            component->add(cast);
            return true;
        }
        catch (...)
        {
            return false;
        }
    };
}

namespace game
{
    base::base(int _max_units_count)
            : object(balance::base_health(), balance::base_armor()), max_units_count(_max_units_count)
    {
        factory = std::make_unique<units::unit_factory>(*mediator_ref);
    }

    std::shared_ptr<units::unit> base::create_unit(common::coordinates _to)
    {
        auto new_unit = factory->create(selected_unit.value());
        new_unit->set_mediator(*mediator_ref);
        units.emplace_back(*new_unit);
        new_unit->add_subscriber(*this);
        mediator_ref->send(commands::create_object_command(*this, new_unit, _to));
        logger::logger_proxy::inst() << "Created unit at: " << _to << "\n";
        return new_unit;
    }

    void base::update(const game::units::unit& _object)
    {
        using namespace units;
        units.erase(std::remove_if(units.begin(), units.end(), [&_object](const auto& x)
        { return x.get() == _object; }), units.end());
    }

    std::shared_ptr<views::unit_tree_component> base::get_tree_view() const
    {
        auto component = std::make_shared<views::unit_tree_composite>(views::unit_tree_composite());

        for (auto& unit : units)
        {
            if (try_cast_and_call<game::units::warriors::warrior>(component, unit))
            { continue; }
            if (try_cast_and_call<game::units::shooters::shooter>(component, unit))
            { continue; }
            if (try_cast_and_call<game::units::mages::mage>(component, unit))
            { continue; }
        }
        return component;
    }

    std::shared_ptr<save_load::memento> base::save()
    {
        return std::make_shared<base_memento>(health, armor, typeid(*this), max_units_count);
    }

    void base::restore(std::shared_ptr<save_load::memento> _memento)
    {
        object::restore(_memento);
        auto memento = std::static_pointer_cast<base_memento>(_memento);
        max_units_count = memento->max_units;
    }

    std::vector<int> base::get_units_ids_from_mapping(std::map<game::units::unit*, int>& _mapping)
    {
        std::vector<int> res_vec;
        for (auto& unit : units)
        {
            res_vec.push_back(_mapping[&unit.get()]);
        }

        return res_vec;
    }
}



