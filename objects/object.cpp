#include "object.h"

namespace game
{
    object::object(int _max_health, int _defend_point = 0)
            : health(_max_health), armor(_defend_point)
    {
    }
}


