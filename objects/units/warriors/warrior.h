#ifndef LAB1_WARRIOR_H
#define LAB1_WARRIOR_H

#include "../unit.h"

namespace game::units::warriors
{
    class warrior : public unit
    {
    public:
        warrior(int _health, int _armor, int _attack);

        ~warrior() override = 0;
    };
}


#endif //LAB1_WARRIOR_H
