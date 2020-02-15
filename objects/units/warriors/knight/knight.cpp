#include "knight.h"
#include "balance.h"


game::units::warriors::knight::knight()
        : warrior(balance::knight_health(), balance::knight_armor(), balance::knight_attack())
{
}
