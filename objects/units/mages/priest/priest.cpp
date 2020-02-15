#include "priest.h"
#include "balance.h"

namespace game::units::mages
{
    priest::priest()
            : mage(balance::priest_health(), balance::priest_mana(), balance::priest_armor(), balance::priest_attack(),
                   balance::priest_attack_range())
    {
    }
}


