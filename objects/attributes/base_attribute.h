#ifndef LAB1_BASE_ATTRIBUTE_H
#define LAB1_BASE_ATTRIBUTE_H

#include <save_load/memento.h>

namespace game::attributes
{
    class base_attribute : public save_load::memento
    {
    protected:
        int value = 0;
    public:
        base_attribute() = default;
        int get_value() const
        { return value; }

        base_attribute(int _value);

        virtual void decrease(int _value);

        virtual void increase(int _value);
    };
}

#endif //LAB1_BASE_ATTRIBUTE_H
