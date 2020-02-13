#include "archer.h"
#include "balance.h"

game::units::shooters::archer::archer()
{
    health = balance::archer_health();
    attack_point = balance::archer_attack();
    defend_point = balance::archer_armor();
}
