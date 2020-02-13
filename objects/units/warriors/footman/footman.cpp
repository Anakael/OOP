#include "footman.h"
#include "balance.h"

game::units::warriors::footman::footman()
{
    health = balance::footman_health();
    attack_point = balance::footman_attack();
    defend_point = balance::footman_armor();
}
