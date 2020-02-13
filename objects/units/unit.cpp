#include "unit.h"
#include <field/field.h>

namespace game::units
{
    void unit::move_to(int _x, int _y)
    {
        x = _x;
        y = _y;
        field->delete_object(x, y);
        field->add_object(*this, _x, _y);
    }

    unit::~unit()
    {

    }

    bool unit::operator==(const unit& other)
    {
        return false;
    }
}
