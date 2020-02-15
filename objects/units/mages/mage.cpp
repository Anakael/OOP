#include "mage.h"

namespace game::units::mages
{
    void mage::restore_mana(int mana_point)
    {
        mana.increase(mana_point);
    }

    mage::mage(int _health, int _mana, int _armor, int _attack, int _attack_range)
            : unit(_health, _armor, _attack, _attack_range), mana(_mana)
    {
    }

    mage::~mage()
    = default;
}
