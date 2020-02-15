#include "rifleman.h"
#include "balance.h"

game::units::shooters::rifleman::rifleman()
        : shooter(balance::rifleman_health(), balance::rifleman_armor(), balance::rifleman_attack(),
                  balance::rifleman_attack_range())
{
}
