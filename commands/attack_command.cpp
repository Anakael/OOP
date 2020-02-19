#include "attack_command.h"
#include <mediator/mediator.h>
#include <iostream>

namespace game::commands
{
    attack_command::attack_command(object& _sender, common::coordinates _to)
            : command(_sender), to(_to)
    {
    }

    void attack_command::operator()(field::field& _field)
    {
        auto& unit_sender = dynamic_cast<units::unit&>(sender);
        if (!_field.get(to).get_object())
        {
            auto from = unit_sender.get_coords();
            if (from.distance_to(to) <= unit_sender.get_attack_attribute().get_attack_range())
            {
                _field.get(to).get_object()->take_damage(unit_sender.get_attack_attribute());
            }
            else
            {
                std::cout << "To much distance" << std::endl;
            }
        }
        else
        {
            std::cout << "Nothing to attack" << std::endl;
        }

    }
}


