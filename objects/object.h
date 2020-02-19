#ifndef LAB1_OBJECT_H
#define LAB1_OBJECT_H

#include <objects/attributes/protected_attribute.h>
#include <objects/attributes/attack_attribute.h>
#include <mediator/component.h>
#include <common/coordinates.h>

namespace game
{
    class object : public component
    {
    protected:
        attributes::protected_attribute health;
        attributes::base_attribute armor;

        virtual void die();
    public:
        object(int _max_health, int _defend_point);

        void increase_armor(int _armor_point);

        void take_healing(int _heal_point);

        void take_damage(const attributes::attack_attribute& _attack);

        int get_health() const
        { return health.get_value(); }

        common::coordinates get_coords() const;

        int get_defend_point() const
        { return armor.get_value(); }
    };
}

#endif //LAB1_OBJECT_H
