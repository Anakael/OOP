#include "field_iterator.h"

namespace game::field
{
    void field_iterator::swap(field_iterator& first, field_iterator& second)
    {
        using std::swap;

        swap(first.current_coords, second.current_coords);
        swap(first.inner_field, second.inner_field);
    }

    field_iterator::field_iterator(field& _field, common::coordinates _coords)
            : current_coords(_coords)
    {
        inner_field = std::make_unique<field>(_field);
    }

    field_iterator::field_iterator(const field_iterator& other)
    {
        field_iterator obj(*other.inner_field, other.current_coords);
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
        auto current = this;
        inc();
        return *current;
    }

    field_iterator& field_iterator::operator++(int)
    {
        inc();
        return *this;
    }

    void field_iterator::inc()
    {
        if (current_coords.x + 1 > inner_field->width)
        {
            current_coords.x = 0;
            ++current_coords.y;
        } else
        {
            ++current_coords.x;
        }
    }

    bool field_iterator::operator==(const field_iterator& rhs) const
    {
        return current_coords.x == rhs.current_coords.x && current_coords.y == rhs.current_coords.y;
    }

    bool field_iterator::operator!=(const field_iterator& rhs) const
    {
        return !(*this == rhs);
    }

    cell& field_iterator::operator*()
    {
        return inner_field->cells[current_coords.x][current_coords.y];
    }
}