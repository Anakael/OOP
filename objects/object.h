#ifndef LAB1_OBJECT_H
#define LAB1_OBJECT_H

#include <objects/attributes/protected_attribute.h>

namespace game
{
    class object
    {
    protected:
        attributes::protected_attribute health;
        attributes::base_attribute armor;

    public:
        object(int _max_health, int _defend_point);

        int get_health() const
        { return health.get_value(); }

        int get_defend_point() const
        { return armor.get_value(); }
    };
}

#endif //LAB1_OBJECT_H
