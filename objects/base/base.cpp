#include "base.h"
#include <iostream>
#include <commands/create_object_command.h>

namespace game
{
    base::base(mediator& mediator, int _max_units_count, int health, int _armor_point)
            : object(health, _armor_point), max_units_count(_max_units_count)
    {
        mediator_ref = &mediator;
        factory = std::make_unique<units::unit_factory>(*mediator_ref);
        health = health;
    }

    std::shared_ptr<units::unit> base::create_unit(unit_enum type, common::coordinates _to)
    {
        if (units.size() + 1 <= max_units_count)
        {
            auto new_unit = factory->create(type);
            units.emplace_back(*new_unit);
            new_unit->add_subscriber(*this);
            mediator_ref->send(commands::create_object_command(*this, new_unit, _to));
            return new_unit;
        }
        else
        {
            std::cout << "Max count of units reached" << std::endl;
        }
        return nullptr;
    }

    void base::update(const game::units::unit& _object)
    {
        using namespace units;
        units.erase(std::remove_if(units.begin(), units.end(), [&_object](const auto& x)
        { return x.get() == _object; }), units.end());
    }
}



