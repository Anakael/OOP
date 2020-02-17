#ifndef LAB1_FIELD_ITERATOR_H
#define LAB1_FIELD_ITERATOR_H

#include <iterator>
#include <objects/object.h>
#include <memory>
#include "field.h"
#include <common/coordinates.h>

namespace game::field
{
    class field_iterator : public std::iterator<std::input_iterator_tag, object>
    {
    private:
        std::unique_ptr<field> inner_field;
        common::coordinates current_coords;

        static void swap(field_iterator& first, field_iterator& second);

        void inc();

    public:
        field_iterator(field& _field, common::coordinates _coords);

        field_iterator(const field_iterator& other);

        field_iterator& operator=(field_iterator other);

        field_iterator(field_iterator&& other) noexcept;

        field_iterator& operator=(field_iterator&& other) noexcept;

        field_iterator& operator++();

        field_iterator& operator++(int);

        bool operator==(const field_iterator& rhs) const;

        bool operator!=(const field_iterator& rhs) const;

        cell& operator*();
    };
}

#endif //LAB1_FIELD_ITERATOR_H
