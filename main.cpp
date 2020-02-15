#include <iostream>

#include <field/field.h>
#include <field/field_iterator.h>
#include <objects/units/unit_factory.h>
#include <field/neutral_objects/neutral_objects/restoring_object.h>

int main()
{
    auto tmp_field = game::field::field(1, 1, 100);
    game::units::unit_factory factory;
    auto f = factory.create(unit_enum::FOOTMAN);
    auto neu_obj = game::field::neutral_objects::restoring_object();
    f->pick_up_neutral_object(neu_obj);
    return 0;
}
