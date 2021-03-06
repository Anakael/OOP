#ifndef LAB1_PROTECTED_ATTRIBUTE_H
#define LAB1_PROTECTED_ATTRIBUTE_H

#include "base_attribute.h"

namespace game::attributes
{
    class protected_attribute : public base_attribute
    {
    private:
        int max_value = 0;
    public:
        protected_attribute() = default;
        explicit protected_attribute(int _max_value);

        int get_max_value() const
        { return max_value; }

        protected_attribute(int _max_value, int _initial_value);

        void increase(int _value) override;

        void decrease(int _value) override;
    };
}

#endif //LAB1_PROTECTED_ATTRIBUTE_H
