#ifndef LAB1_UNIT_H
#define LAB1_UNIT_H

#include <objects/object.h>
#include <observer/publisher.h>
#include <field/neutral_objects/neutral_objects/neutral_object.h>
#include <memory>
#include <common/coordinates.h>
#include <objects/attributes/attack_attribute.h>

namespace game::field
{
    class field;
    class cell;
}

namespace game::units
{
class unit : public game::object, public publisher
    {
    protected:
        void die() override;

        attributes::attack_attribute attack;

    public:
        unit(int _health, int _armor, int _attack, int attack_range);

        attributes::attack_attribute get_attack_attribute() const { return attack; }

        virtual void move_to(common::coordinates _to);

        void pick_up_neutral_object(game::field::neutral_objects::neutral_object& neutral_object);

        bool operator==(const unit& other);

        virtual void attack_to(common::coordinates _to);

        ~unit() override = 0;
    };
}

#endif //LAB1_UNIT_H
