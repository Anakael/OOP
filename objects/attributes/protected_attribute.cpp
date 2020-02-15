#include "protected_attribute.h"

namespace game::attributes
{
    protected_attribute::protected_attribute(int _max_value)
            : base_attribute(_max_value), max_value(_max_value)
    {
    }

    void protected_attribute::increase(int _value)
    {
        int new_value = value + _value;
        value = new_value < max_value ? new_value : max_value;
    }

    void protected_attribute::decrease(int _value)
    {
        int new_value = value - _value;
        value = new_value > 0 ? new_value : 0;
    }

    protected_attribute::protected_attribute(int _max_value, int _initial_value)
            : base_attribute(_initial_value), max_value(_max_value)
    {

    }
}


