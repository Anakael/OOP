#include "soucerer.h"
#include "balance.h"

namespace game::units::mages
{
    soucerer::soucerer()
    {
        max_health = health = balance::sourcerer_health();
        max_mana = mana = balance::sourcerer_mana();
        attack_point = balance::sourcerer_attack();
        defend_point = balance::sourcerer_armor();
    }
}


