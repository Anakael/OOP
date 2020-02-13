#ifndef LAB1_UNIT_FACTORY_H
#define LAB1_UNIT_FACTORY_H

#include <objects/units/unit.h>
#include "unit_enum.h"
#include <memory>

namespace game::units
{
    class unit_factory
    {
    public:
        virtual std::unique_ptr<unit> create(unit_enum type);

        ~unit_factory();
    };
}

#endif //LAB1_UNIT_FACTORY_H
