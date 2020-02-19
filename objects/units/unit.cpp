#include "unit.h"
#include <iostream>
#include <commands/attack_command.h>
#include <commands/pick_up_neutral_object_command.h>
#include <mediator/mediator.h>
#include <commands/move_command.h>

namespace game::units
{
    unit::~unit()
    = default;

    void unit::attack_to(common::coordinates _to)
    {
        mediator_ref->send(commands::attack_command(*this, _to));
    }

    void unit::die()
    {
        notify(*this);
        object::die();
    }

    bool unit::operator==(const unit& other)
    {
        return this == &other;
    }

    void unit::pick_up_neutral_object(game::field::neutral_objects::neutral_object& _neutral_object)
    {
        mediator_ref->send(commands::pick_up_neutral_object_command(*this, _neutral_object));
    }

    unit::unit(int _health, int _armor, int _attack, int _attack_range)
            : object(_health, _armor), attack(_attack, _attack_range)
    {
    }

    void unit::move_to(common::coordinates _to)
    {
        mediator_ref->send(commands::move_command(*this, _to));
    }
}
