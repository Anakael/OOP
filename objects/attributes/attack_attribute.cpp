#include "attack_attribute.h"

namespace game::attributes
{
    attack_attribute::attack_attribute(int _attack_points, int _attack_range = 0)
            : protected_attribute(5000, _attack_points), attack_range(_attack_range)
    {

    }
}


