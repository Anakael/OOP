#ifndef LAB1_FIELD_H
#define LAB1_FIELD_H

#include <objects/object.h>
#include "cell.h"
#include <vector>
#include <memory>
#include <common/coordinates.h>
#include <mediator/component.h>
#include <save_load/originator.h>
#include <save_load/memento.h>

namespace save_load
{
    class save_command;
}

namespace game::field
{
    class field_iterator;

    class field : public save_load::originator
    {
        friend class field_iterator;

    private:
        size_t length;
        size_t width;
        int max_objects_count;
        int count_of_objects;
        std::unique_ptr<std::unique_ptr<cell[]>[]> cells;

        static void swap(field& first, field& second);


    public:
        field(size_t _length, size_t _width, int _max_objects_count);

        field(const field& other);

        field& operator=(field other);

        field(field&& other) noexcept;

        field& operator=(field&& other) noexcept;

        int get_count_of_objects() const
        { return count_of_objects; }

        size_t get_length() const
        { return length; }

        size_t get_width() const
        { return width; }

        void move_object(common::coordinates _from, common::coordinates _to);

        void add_object(std::shared_ptr<object> new_object, common::coordinates _to);

        void delete_object(common::coordinates _to);

        cell& get(common::coordinates _from);

        field_iterator begin();

        field_iterator end();

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento> _imemento) override;

        ~field() override;

        class field_memento : public save_load::memento
        {
        private:
            size_t length;
            size_t width;
            int max_objects_count;
            int count_objects;
            std::vector<std::vector<std::shared_ptr<cell::cell_memento>>> cells_mementos;

            friend class field;

            friend class save_load::save_command;

        public:
            field_memento(size_t _length, size_t _width, int _max_objects_count, int _count_objects,
                          std::vector<std::vector<std::shared_ptr<cell::cell_memento>>>&& _cells_mementos)
                    : length(_length), width(_width), max_objects_count(_max_objects_count),
                      count_objects(_count_objects),
                      cells_mementos(_cells_mementos)
            {
            }
        };
    };
}

#endif //LAB1_FIELD_H
