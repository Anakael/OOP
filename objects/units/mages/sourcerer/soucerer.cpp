#include "soucerer.h"
#include "balance.h"

namespace game::units::mages
{
    soucerer::soucerer()
    {
        health = balance::sourcerer_health();
        attack_point = balance::sourcerer_attack();
        defend_point = balance::sourcerer_armor();
    }
}


