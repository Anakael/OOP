#include "footman.h"
#include "balance.h"

game::units::warriors::footman::footman()
        : warrior(balance::footman_health(), balance::footman_armor(), balance::footman_attack())
{
}
