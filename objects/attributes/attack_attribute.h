#ifndef LAB1_ATTACK_ATTRIBUTE_H
#define LAB1_ATTACK_ATTRIBUTE_H

#include "protected_attribute.h"

namespace game::attributes
{
    class attack_attribute : public protected_attribute
    {
    private:
        int attack_range;
    public:
        attack_attribute(int _attack_points, int _attack_range);
    };
}




#endif //LAB1_ATTACK_ATTRIBUTE_H
