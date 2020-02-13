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
    private:
        int x;
        int y;

    protected:
        std::shared_ptr<game::field::field> field;

        int attack_point;

    public:
        void move_to(int x, int y);

        bool operator==(const unit& other);

        ~unit();
    };
}

#endif //LAB1_UNIT_H
