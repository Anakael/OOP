#ifndef LAB1_MAGE_H
#define LAB1_MAGE_H

#include <objects/units/unit.h>
#include <objects/attributes/protected_attribute.h>

namespace game::units::mages
{
    class mage : public unit
    {
    protected:
        attributes::protected_attribute mana;
    public:
        mage(int _health, int _mana, int _armor, int _attack, int _attack_range);

        void restore_mana(int mana_point);

        ~mage() override = 0;
    };
}


#endif //LAB1_MAGE_H
