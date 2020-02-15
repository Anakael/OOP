#include "soucerer.h"
#include "balance.h"

namespace game::units::mages
{
    soucerer::soucerer()
            : mage(balance::sourcerer_health(), balance::sourcerer_mana(), balance::sourcerer_armor(), balance::sourcerer_attack(),
                      balance::sourcerer_attack_range())
    {
    }
}


