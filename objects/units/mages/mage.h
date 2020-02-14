#ifndef LAB1_MAGE_H
#define LAB1_MAGE_H

#include <objects/units/unit.h>

namespace game::units::mages
{
    class mage : public unit
    {
    protected:
        int max_mana;
        int mana;
    public:
        void restore_mana(int mana_point);
    };
}


#endif //LAB1_MAGE_H
