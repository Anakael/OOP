#include "unit.h"
#include <iostream>
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
        health.increase(heal_point);
    }

    void unit::die()
    {
        notify(*this);
    }

    void unit::increase_armore(int armor_point)
    {
        armor.increase(armor_point);
    }

    bool unit::operator==(const unit& other)
    {
        return this == &other;
    }

    void unit::get_damage(int damage)
    {
        health.decrease(damage);
        if (!health.get_value())
        {
            die();
        }
    }

    void unit::pick_up_neutral_object(game::field::neutral_objects::neutral_object& neutral_object)
    {
        if (!neutral_object.affect_to_unit(*this))
        {
            std::cout << "Unable to pick up such neutral object for this unit" << std::endl;
        }
    }

    unit::unit(int _health, int _armor, int _attack, int _attack_range)
        : object(_health, _armor), attack(_attack, _attack_range)
    {
    }
}
