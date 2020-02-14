#include "hill.h"
#include <objects/units/warriors/warrior.h>
#include <objects/units/warriors/knight/knight.h>

namespace game::field::landscape
{
    void hill::affect_to_unit(game::units::unit_proxy& _unit_proxy)
    {
        if (_unit_proxy.get_type_of_inner_unit() == typeid(units::warriors::warrior))
        {
            _unit_proxy.set_can_attack_from(false);
        }
        if (_unit_proxy.get_type_of_inner_unit() == typeid(units::warriors::knight))
        {
            _unit_proxy.set_can_move_to(false);
        }
    }
}
