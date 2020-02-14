#ifndef LAB1_HILL_H
#define LAB1_HILL_H

#include <field/landscape/landscape.h>

namespace game::field::landscape
{
    class hill : public landscape
    {
    public:
        void affect_to_unit(units::unit_proxy &_unit_proxy) override;
    };
}

#endif //LAB1_HILL_H
