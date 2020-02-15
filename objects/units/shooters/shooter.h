#ifndef LAB1_SHOOTER_H
#define LAB1_SHOOTER_H

#include <objects/units/unit.h>

namespace game::units::shooters
{
    class shooter : public unit
    {
    public:
        shooter(int _health, int _armor, int _attack, int _attack_range);

        ~shooter() override = 0;
    };
}




#endif //LAB1_SHOOTER_H
