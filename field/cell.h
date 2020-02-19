#ifndef LAB1_CELL_H
#define LAB1_CELL_H

#include "landscape/landscape.h"
#include "landscape/plain/plain.h"
#include "observer/subscriber.h"
#include <memory>

namespace game::field
{
    class cell
    {
    private:
        landscape::landscape* landscape = new landscape::plain;
        std::shared_ptr<game::object> object;
        static void swap(cell& first, cell& second);
    public:
        cell();

        std::shared_ptr<game::object> get_object() const { return object; };

        landscape::landscape* get_landscape() const { return landscape; };

        void set_object(std::shared_ptr<game::object> _object);

        void delete_object();
    };
}

#endif //LAB1_CELL_H
