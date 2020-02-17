#include "cell.h"

#include <utility>

namespace game::field
{
    void cell::delete_object()
    {
        object.reset();
    }

    cell::cell()
    = default;

    void cell::swap(cell& first, cell& second)
    {
        using std::swap;
        swap(first.landscape, second.landscape);
        swap(first.object, second.object);
    }

    void cell::set_object(std::shared_ptr<game::object> _object)
    {
        object = std::move(_object);
    }
}
