#ifndef LAB1_UNIT_H
#define LAB1_UNIT_H

#include <objects/object.h>
#include <observer/publisher.h>
#include <field/neutral_objects/neutral_objects/neutral_object.h>
#include <memory>
#include <utility>
#include <common/coordinates.h>
#include <objects/attributes/attack_attribute.h>

namespace save_load
{
    class save_command;
}

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

        attributes::attack_attribute get_attack_attribute() const
        { return attack; }

        virtual void move_to(common::coordinates _to);

        void pick_up_neutral_object(game::field::neutral_objects::neutral_object& neutral_object);

        bool operator==(const unit& other);

        virtual void attack_to(object& _target);

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento> _memento) override;

        ~unit() override = 0;

        class unit_memento : public object_memento
        {
        private:
        protected:
            attributes::attack_attribute attack;

            friend class save_load::save_command;

        public:
            unit_memento(game::attributes::protected_attribute _health, game::attributes::base_attribute _armor, std::type_index _object_type, attributes::attack_attribute _attack)
                    : object_memento(std::move(_health), std::move(_armor), _object_type), attack(std::move(_attack))
            {}
        };
    };
}

#endif //LAB1_UNIT_H
