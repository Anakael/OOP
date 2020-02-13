#include "rifleman.h"
#include "balance.h"

game::units::shooters::rifleman::rifleman()
{
    health = balance::rifleman_health();
    attack_point = balance::rifleman_attack();
    defend_point = balance::rifleman_armor();
}
