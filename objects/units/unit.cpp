#include "unit.h"
#include <commands/attack_command.h>
#include <commands/pick_up_neutral_object_command.h>
#include <mediator/mediator.h>
#include <commands/move_command.h>
#include <logger/logger_proxy.h>

namespace game::units
{
    unit::~unit()
    = default;

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
        logger::logger_proxy::inst() << "Pick up neutral object from: " << _neutral_object.get_coords() << "\n";
        mediator_ref->send(commands::pick_up_neutral_object_command(*this, _neutral_object));
    }

    unit::unit(int _health, int _armor, int _attack, int _attack_range)
            : object(_health, _armor), attack(_attack, _attack_range)
    {
    }

    void unit::move_to(common::coordinates _to)
    {
        logger::logger_proxy::inst() << "Move object from: " << get_coords() << " to:" << _to << "\n";
        mediator_ref->send(commands::move_command(*this, _to));
    }

    void unit::attack_to(object& _target)
    {
        logger::logger_proxy::inst() << "Attack unit at: " << _target.get_coords() << "\n";
        mediator_ref->send(commands::attack_command(*this, _target));
    }
}
