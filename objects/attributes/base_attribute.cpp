#include "base_attribute.h"

namespace game::attributes
{
    base_attribute::base_attribute(int _value)
            : value(_value)
    {
    }

    void base_attribute::decrease(int _value)
    {
        value -= _value;
    }

    void base_attribute::increase(int _value)
    {
        value += _value;
    }
}


