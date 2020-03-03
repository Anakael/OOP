#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "landscape/landscape.h"
#include "landscape/plain/plain.h"
#include "observer/subscriber.h"
#include <memory>
#include <utility>
#include <save_load/originator.h>
#include <save_load/memento.h>

namespace save_load
{
    class save_command;
}

namespace game::field
{
    class field;

    class cell : public save_load::originator
    {
    private:
        std::shared_ptr<landscape::landscape> landscape = std::make_shared<landscape::plain>();
        std::shared_ptr<game::object> object;

        static void swap(cell& first, cell& second);

    public:
        cell();

        std::shared_ptr<game::object> get_object() const
        { return object; };

        std::shared_ptr<landscape::landscape> get_landscape() const
        { return landscape; };

        void set_object(std::shared_ptr<game::object> _object);

        std::shared_ptr<save_load::memento> save() override;

        void restore(std::shared_ptr<save_load::memento> _memento) override;

        void delete_object();

        class cell_memento : public save_load::memento
        {
        private:
            std::type_index landscape_type;
            std::shared_ptr<game::object::object_memento> object;

            friend class cell;

            friend class save_load::save_command;

        public:
            cell_memento(std::type_index _landscape_type, std::shared_ptr<game::object::object_memento> _object)
                    : landscape_type(_landscape_type), object(std::move(_object))
            {
            }
        };

    private:
        template <typename T>
        static std::shared_ptr<T> try_init_object(cell::cell_memento& _memento)
        {
            if (_memento.object->object_type == typeid(T))
            {
                return std::make_shared<T>();
            }
            else
            {
                return nullptr;
            }
        }

        template <typename T>
        static std::shared_ptr<T> try_init_landscape(cell::cell_memento& _memento)
        {
            if (_memento.landscape_type == typeid(T))
            {
                return std::make_shared<T>();
            }
            else
            {
                return nullptr;
            }
        }
    };
}

#endif //LAB1_CELL_H
