#ifndef LAB1_FIELD_H
#define LAB1_FIELD_H

#include <objects/object.h>
#include "cell.h"
#include <vector>
#include <memory>
#include <common/coordinates.h>
#include <mediator/component.h>

namespace game::field
{
    class field_iterator;

    class field
    {
        friend class field_iterator;

    private:
        size_t length;
        size_t width;
        int max_objects_count;
        int count_of_objects;
        std::unique_ptr<std::unique_ptr<game::field::cell[]>[]> cells;

        static void swap(field& first, field& second);

    public:
        field(size_t _length, size_t _width, int _max_objects_count);

        field(const field& other);

        field& operator=(field other);

        field(field&& other) noexcept;

        field& operator=(field&& other) noexcept;

        int get_count_of_objects() const
        { return count_of_objects; }

        void move_object(common::coordinates _from, common::coordinates _to);

        void add_object(std::shared_ptr<object> new_object, common::coordinates _to);

        void delete_object(common::coordinates _to);

        cell& get(common::coordinates _from);

        field_iterator begin();

        field_iterator end();

        ~field();
    };
}

#endif //LAB1_FIELD_H
