#include "field.h"
#include <iostream>
#include <memory>
#include <objects/object.h>
#include "field_iterator.h"

namespace game::field
{
    field::field(int _length, int _width, int _max_objects_count)
            : length(_length), width(_width),
              max_objects_count(_max_objects_count > _length * _width ? _length * _width : _max_objects_count),
              count_of_objects(0),
              cells(new std::unique_ptr<cell[]>[_length])
    {
        for (int i = 0; i < length; ++i)
        {
            cells[i] = std::make_unique<cell[]>(width);
        }
    }

    void field::delete_object(int x, int y)
    {
        cells[x][y].delete_object();
        --count_of_objects;
    }

    void field::add_object(object& new_object, int x, int y)
    {
        if (count_of_objects + 1 <= max_objects_count)
        {
            if (cells[x][y].get_object() == nullptr)
            {
                cells[x][y].set_object(new_object);
                ++count_of_objects;
            }
            else
            {
                std::cout << "Cell is not empty" << std::endl;
            }

        } else
        {
            std::cout << "Unable to add object. Max count of objects limit is reached" << std::endl;
        }
    }

    void field::swap(field& first, field& second)
    {
        using std::swap;
        swap(first.length, second.length);
        swap(first.width, second.width);
        swap(first.max_objects_count, second.max_objects_count);
        swap(first.count_of_objects, second.count_of_objects);
        swap(first.cells, second.cells);
    }

    field::field(const field& other)
    {
        field obj(other.length, other.width, other.max_objects_count);
        obj.count_of_objects = other.count_of_objects;
        obj.cells = std::make_unique<std::unique_ptr<cell[]>[]>(other.length);
        for (int i = 0; i < other.length; ++i)
        {
            obj.cells[i] = std::make_unique<cell[]>(width);
            for (int j = 0; j < other.width; ++j)
            {
                obj.cells[i][j] = other.cells[i][j];
            }
        }
        swap(*this, obj);
    }

    field& field::operator=(field other)
    {
        swap(*this, other);
        return *this;
    }

    field::field(field&& other) noexcept
    {
        swap(*this, other);
    }

    field& field::operator=(field&& other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    field::~field()
    {
    }

    field_iterator field::begin()
    {
        return field_iterator(*this, 0, 0);
    }

    field_iterator field::end()
    {
        return field_iterator(*this, width-1, length-1);
    }
}

