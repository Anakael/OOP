#include "mage.h"

namespace game::units::mages
{
    void mage::restore_mana(int mana_point)
    {
        int new_health = health + mana_point;
        health = new_health < max_health ? new_health : max_health;
    }
}
