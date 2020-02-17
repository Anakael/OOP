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
        std::shared_ptr<landscape::landscape> landscape;
        std::shared_ptr<game::object> object;
        std::shared_ptr<game::object> neutral_element;
        static void swap(cell& first, cell& second);
    public:
        cell();

        std::shared_ptr<game::object> get_object() const { return object; };

        void set_object(std::shared_ptr<game::object> _object);

        void delete_object();
    };
}

#endif //LAB1_CELL_H
