#include "cell.h"

namespace game::field
{
    void cell::delete_object()
    {
        object.reset();
    }

    cell::cell(const cell& other)
    {
        landscape.reset(other.landscape.get());
        object.reset(other.object.get());
    }

    cell& cell::operator=(cell other)
    {
        swap(*this, other);
        return *this;
    }

    cell::cell()
    {

    }

    void cell::swap(cell& first, cell& second)
    {
        using std::swap;
        swap(first.landscape, second.landscape);
        swap(first.object, second.object);
    }
}
