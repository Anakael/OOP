#include "priest.h"
#include "balance.h"

namespace game::units::mages
{
    priest::priest()
    {
        health = balance::priest_health();
        attack_point = balance::priest_attack();
        defend_point = balance::priest_armor();
    }
}


