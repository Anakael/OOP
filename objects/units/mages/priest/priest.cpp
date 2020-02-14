#include "priest.h"
#include "balance.h"

namespace game::units::mages
{
    priest::priest()
    {
        max_health = health = balance::priest_health();
        max_mana = mana = balance::priest_mana();
        attack_point = balance::priest_attack();
        defend_point = balance::priest_armor();
    }
}


