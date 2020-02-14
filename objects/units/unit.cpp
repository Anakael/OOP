#include "unit.h"
#include <field/field.h>

namespace game::units
{
    void unit::move_to(int _x, int _y)
    {
        //TODO: Remove from this
        field->add_object(*this, _x, _y);
    }

    unit::~unit()
    = default;

    void unit::attack_to(int x, int y)
    {
        //TODO: realize
    }

    void unit::get_healing(int heal_point)
    {
        int new_health = health + heal_point;
        health = new_health < max_health ? new_health : max_health;
    }

    void unit::die()
    {
        // TODO: realize
    }

    void unit::increase_armore(int armor_point)
    {
        armor_point += armor_point;
    }

    bool unit::operator==(const unit& other)
    {
        return this == &other;
    }
}
