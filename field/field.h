#ifndef LAB1_FIELD_H
#define LAB1_FIELD_H

#include <objects/object.h>
#include "cell.h"
#include <vector>
#include <memory>

namespace game::field
{
    class field_iterator;
    class field
    {
        friend class field_iterator;
    private:
        int length;
        int width;
        int max_objects_count;
        int count_of_objects;
        std::unique_ptr<std::unique_ptr<game::field::cell[]>[]> cells;
        static void swap(field& first, field& second);
    public:
        field(int _length, int _width, int _max_objects_count);
        field(const field& other);
        field& operator=(field other);
        field(field&& other) noexcept;
        field& operator=(field&& other) noexcept;

        int get_count_of_objects() { return count_of_objects; }

        void add_object(object& new_object, int x, int y);

        void delete_object(int x, int y);

        field_iterator begin();
        field_iterator end();

        ~field();
    };
}

#endif //LAB1_FIELD_H
