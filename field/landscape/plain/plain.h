#ifndef LAB1_PLAIN_H
#define LAB1_PLAIN_H

#include <field/landscape/landscape.h>

namespace game::field::landscape
{
    class plain : public landscape
    {
    public:
        void affect_to_unit(units::unit_proxy &_unit_proxy) override;
    };
}

#endif //LAB1_PLAIN_H
