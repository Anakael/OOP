#include "unit_proxy.h"
#include <iostream>

namespace game::units
{
    void unit_proxy::move_to(common::coordinates _to)
    {
        if (can_move_to)
        {
            internal_unit.move_to(_to);
        } else
        {
            std::cout << "Can't move to that cell" << std::endl;
        }
    }

    unit_proxy::unit_proxy(unit& _unit)
            : unit(_unit), internal_unit(_unit)
    {

    }

    std::type_index unit_proxy::get_type_of_inner_unit()
    {
        return typeid(internal_unit);
    }
}
