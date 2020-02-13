#include "knight.h"
#include "balance.h"

game::units::warriors::knight::knight()
{
    health = balance::knight_health();
    attack_point = balance::knight_attack();
    defend_point = balance::knight_armor();
}
