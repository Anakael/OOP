#ifndef LAB1_WATER_H
#define LAB1_WATER_H

#include <field/landscape/landscape.h>

namespace game::field::landscape
{
    class water : public landscape
    {
    public:
        void affect_to_unit(units::unit_proxy &_unit_proxy) override;
    };
}

#endif //LAB1_WATER_H
