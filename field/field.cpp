#include "field.h"
#include <iostream>
#include <memory>
#include <objects/object.h>
#include "field_iterator.h"

namespace game::field
{
    field::field(size_t _length, size_t _width, int _max_objects_count)
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

    void field::delete_object(common::coordinates _to)
    {
        if (cells[_to.x][_to.y].get_object() != nullptr)
        {
            cells[_to.x][_to.y].delete_object();
            --count_of_objects;
        }
        else
        {
            std::cout << "Cell is empty" << std::endl;
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
    = default;

    field_iterator field::begin()
    {
        return field_iterator(*this, common::coordinates(0, 0));
    }

    field_iterator field::end()
    {
        return field_iterator(*this, common::coordinates(width, length - 1));
    }

    cell& field::get(common::coordinates _from)
    {
        return cells[_from.x][_from.y];
    }

    void field::add_object(std::shared_ptr<object> new_object, common::coordinates _to)
    {
        if (count_of_objects + 1 <= max_objects_count)
        {
            if (!cells[_to.x][_to.y].get_object())
            {
                cells[_to.x][_to.y].set_object(std::move(new_object));
                ++count_of_objects;
            }
            else
            {
                std::cout << "Cell is not empty" << std::endl;
            }
        }
        else
        {
            std::cout << "Unable target add object. Max count of objects limit is reached" << std::endl;
        }
    }

    void field::move_object(common::coordinates _from, common::coordinates _to)
    {

        auto obj = cells[_from.x][_from.y].get_object();
        if (obj == nullptr)
        {
            std::cout << "Nothing target move" << std::endl;
        }
        else
        {
            add_object(obj, _to);
            delete_object(_from);
        }
    }

    void field::restore(std::shared_ptr<save_load::memento> _imemento)
    {
        auto memento = std::static_pointer_cast<field_memento>(_imemento);
        length = memento->length;
        width = memento->width;
        max_objects_count = memento->max_objects_count;
        count_of_objects = memento->count_objects;
        cells = std::make_unique<std::unique_ptr<cell[]>[]>(length);
        for (int i = 0; i < length; ++i)
        {
            cells[i] = std::make_unique<cell[]>(width);
            for (int j = 0; j < length; ++j)
            {
                cells[i][j].restore(memento->cells_mementos[i][j]);
            }
        }
    }

    std::shared_ptr<save_load::memento> field::save()
    {
        std::vector<std::vector<std::shared_ptr<cell::cell_memento>>> cell_mementos;
        for (int i = 0; i < length; ++i)
        {
            cell_mementos.emplace_back();
            for (int j = 0; j < width; ++j)
            {
                cell_mementos[i].push_back(std::static_pointer_cast<cell::cell_memento>((cells[i][j].save())));
            }
        }

        return std::make_shared<field_memento>(length, width, max_objects_count, count_of_objects,
                                               std::move(cell_mementos));
    }
}

