#include "object.h"
#include <commands/object_die_command.h>
#include <mediator/mediator.h>

namespace game
{
    object::object(int _max_health, int _defend_point = 0)
            : health(_max_health), armor(_defend_point)
    {
    }

    void object::take_damage(const attributes::attack_attribute& _attack)
    {
        health.decrease(_attack.get_value() - armor.get_value());
        if (!health.get_value())
        {
            die();
        }
    }

    void object::die()
    {
        mediator_ref->send(commands::object_die_command(*this));
    }

    void object::take_healing(int _heal_point)
    {
        health.increase(_heal_point);
    }

    void object::increase_armor(int _armor_point)
    {
        armor.increase(_armor_point);
    }

    common::coordinates object::get_coords() const
    {
        return mediator_ref->get_coords(const_cast<object&>(*this));
    }
}


