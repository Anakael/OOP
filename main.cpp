#include <iostream>

#include <field/field.h>
#include <field/field_iterator.h>
#include <mediator/mediator.h>
#include <objects/units/unit_factory.h>
#include <objects/base/base.h>

int main()
{
    using namespace game;
    using namespace game::units;
    auto tmp_field = field::field(2, 2, 100);
    mediator mediator(tmp_field);
    base base(mediator, 10, 5000, 10);
    auto f = base.create_unit(unit_enum::FOOTMAN, common::coordinates(0,1));
    f->move_to(common::coordinates(0,0));
    auto r = base.create_unit(unit_enum::RIFLEMAN, common::coordinates(1, 1));

    for (int i = 0; i < 25; ++i)
    {
        r->attack_to(common::coordinates(0,0));
        std::cout << f->get_health() << std::endl;
    }
    return 0;
}
