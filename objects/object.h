#ifndef LAB1_OBJECT_H
#define LAB1_OBJECT_H

#include <objects/attributes/protected_attribute.h>
#include <objects/attributes/attack_attribute.h>
#include <mediator/component.h>
#include <common/coordinates.h>
#include <save_load/originator.h>
#include <typeindex>

namespace save_load
{
    class save_command;
}

namespace game::field
{
    class cell;
}

namespace game
{
    class object : public component, public save_load::originator
    {
    protected:
        attributes::protected_attribute health;
        attributes::base_attribute armor;

        virtual void die();

    public:
        object() = default;

        object(int _max_health, int _defend_point);

        void increase_armor(int _armor_point);

        void take_healing(int _heal_point);

        void take_damage(const attributes::attack_attribute& _attack);

        int get_health() const
        { return health.get_value(); }

        int get_max_health() const
        { return health.get_max_value(); }

        common::coordinates get_coords() const;

        int get_defend_point() const
        { return armor.get_value(); }

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento>) override;

        ~object() override = 0;

        class object_memento : public save_load::memento
        {
        private:
            friend class save_load::save_command;

            friend class object;

            friend class field::cell;

        protected:
            std::type_index object_type;
            game::attributes::protected_attribute health;
            game::attributes::base_attribute armor;
        public:
            object_memento(game::attributes::protected_attribute _health, game::attributes::base_attribute _armor,
                           std::type_index _object_type)
                    : health(std::move(_health)), armor(std::move(_armor)), object_type(_object_type)
            {}
        };
    };
}

#endif //LAB1_OBJECT_H
