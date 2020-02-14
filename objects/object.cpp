#include "object.h"

namespace game
{
    object::object(int _max_health, int _defend_point)
            : max_health(_max_health), defend_point(_defend_point), health(_max_health)
    {
    }

    object::object()
    = default;
}


