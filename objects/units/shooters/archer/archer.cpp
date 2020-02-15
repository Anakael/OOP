#include "archer.h"
#include "balance.h"

game::units::shooters::archer::archer()
        : shooter(balance::archer_health(), balance::archer_armor(), balance::archer_attack(),
                  balance::archer_attack_range())
{
}
