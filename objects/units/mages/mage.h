#ifndef LAB1_MAGE_H
#define LAB1_MAGE_H

#include <objects/units/unit.h>
#include <objects/attributes/protected_attribute.h>

#include <utility>

namespace save_load
{
    class save_command;
}

namespace game::units::mages
{
    class mage : public unit
    {
    protected:
        attributes::protected_attribute mana;
    public:
        mage(int _health, int _mana, int _armor, int _attack, int _attack_range);

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento> _memento) override;

        void restore_mana(int mana_point);

        ~mage() override = 0;

        class mage_memento : public unit_memento
        {
        private:
            attributes::protected_attribute mana;

            friend class save_load::save_command;

        public:
            mage_memento(game::attributes::protected_attribute _health, game::attributes::base_attribute _armor,
                         std::type_index _object_type, attributes::attack_attribute _attack,
                         attributes::protected_attribute _mana)
                    : unit_memento(std::move(_health), std::move(_armor), _object_type, std::move(_attack)),
                      mana(std::move(_mana))
            {}
        };
    };
}


#endif //LAB1_MAGE_H
