#include <iostream>

#include <field/field.h>
#include <field/field_iterator.h>
#include <objects/units/unit_factory.h>

int main()
{
    auto tmp_field = game::field::field(1, 1, 100);
    game::units::unit_factory factory;
    auto f = factory.create(unit_enum::FOOTMAN);
    tmp_field.add_object(*(f.release()), 0,0);
    auto begin = tmp_field.begin();
    std::cout << "Count of object: " << tmp_field.get_count_of_objects() << std::endl;
    std::cout << (*begin).get_object()->get_health() << std::endl;
    return 0;
}
