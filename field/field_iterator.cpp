#include "field_iterator.h"

namespace game::field
{
    void field_iterator::swap(field_iterator& first, field_iterator& second)
    {
        using std::swap;

        swap(first.current_x, second.current_x);
        swap(first.current_y, second.current_y);
        swap(first.inner_field, second.inner_field);
    }

    field_iterator::field_iterator(field& _field, int x = 0, int y = 0)
            : current_x(x), current_y(y)
    {
        inner_field = std::make_unique<field>(_field);
    }

    field_iterator::field_iterator(const field_iterator& other)
    {
        field_iterator obj(other);
        swap(*this, obj);
    }

    field_iterator& field_iterator::operator=(field_iterator other)
    {
        swap(*this, other);
        return *this;
    }

    field_iterator::field_iterator(field_iterator&& other) noexcept
    {
        swap(*this, other);
    }

    field_iterator& field_iterator::operator=(field_iterator&& other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    field_iterator& field_iterator::operator++()
    {
        auto current = *this;
        inc();
        return current;
    }

    field_iterator field_iterator::operator++(int)
    {
        inc();
        return *this;
    }

    void field_iterator::inc()
    {
        if (current_x + 1 > inner_field->width)
        {
            current_x = 0;
            ++current_y;
        } else
        {
            ++current_x;
        }
    }

    bool field_iterator::operator==(const field_iterator& rhs) const
    {
        return current_x == rhs.current_x && current_y == rhs.current_y;
    }

    bool field_iterator::operator!=(const field_iterator& rhs) const
    {
        return !(*this == rhs);
    }

    cell& field_iterator::operator*()
    {
        return inner_field->cells[current_x][current_y];
    }
}