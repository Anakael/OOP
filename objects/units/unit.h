#ifndef LAB1_UNIT_H
#define LAB1_UNIT_H

#include <objects/object.h>
#include <observer/publisher.h>
#include <field/neutral_objects/neutral_objects/neutral_object.h>
#include <memory>
#include <objects/attributes/attack_attribute.h>

namespace game::field
{
    class field;
}

namespace game::units
{
    class unit : public game::object, public publisher
    {
    protected:
        std::shared_ptr<game::field::field> field;

        void die();

        attributes::attack_attribute attack;

    public:
        unit(int _health, int _armor, int _attack, int attack_range);

        void increase_armore(int armor_point);

        void get_healing(int heal_point);

        void get_damage(int damage);

        virtual void move_to(int x, int y);

        void pick_up_neutral_object(game::field::neutral_objects::neutral_object& neutral_object);

        bool operator==(const unit& other);

        virtual void attack_to(int x, int y);

        virtual ~unit() = 0;
    };
}

#endif //LAB1_UNIT_H
