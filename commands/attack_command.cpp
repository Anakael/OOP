#include "attack_command.h"
#include <mediator/mediator.h>

namespace game::commands
{
    attack_command::attack_command(object& _sender, object& _to)
            : command(_sender), target(_to)
    {
    }

    void attack_command::operator()(field::field& _field)
    {
        auto& unit_sender = dynamic_cast<units::unit&>(sender);
        target.take_damage(unit_sender.get_attack_attribute());
    }
}


