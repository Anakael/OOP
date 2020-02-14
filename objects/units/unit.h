#ifndef LAB1_UNIT_H
#define LAB1_UNIT_H

#include <objects/object.h>
#include <observer/publisher.h>
#include <memory>

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

        int attack_point;

    public:
        void increase_armore(int armor_point);

        void get_healing(int heal_point);

        void die();

        virtual void move_to(int x, int y);

        bool operator==(const unit& other);

        virtual void attack_to(int x, int y);

        ~unit();
    };
}

#endif //LAB1_UNIT_H
