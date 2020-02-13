#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "landscape/landscape.h"
#include "observer/subscriber.h"
#include <memory>

namespace game::field
{
    class cell
    {
    private:
        std::unique_ptr<landscape::landscape> landscape;
        std::unique_ptr<game::object> object;
        static void swap(cell& first, cell& second);
    public:
        cell();
        cell(const cell& other);
        cell& operator=(cell other);

        game::object* get_object() { return object.get(); };

        void set_object(game::object& _object) { object = std::make_unique<game::object>(_object); };

        void delete_object();
    };
}

#endif //LAB1_CELL_H
