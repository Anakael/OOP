#include "object.h"

namespace game
{
    object::object(int _health, int _defend_point)
        : health(_health), defend_point(_defend_point)
    {
    }

    object::object()
        : health(0), defend_point(0)
    {
    }
}


