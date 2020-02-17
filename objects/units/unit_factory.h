#ifndef LAB1_UNIT_FACTORY_H
#define LAB1_UNIT_FACTORY_H

#include <objects/units/unit.h>
#include "unit_enum.h"
#include <memory>
#include <mediator/mediator.h>
#include <mediator/component.h>

namespace game::units
{
    class unit_factory : public component
    {
    public:
        unit_factory(mediator& _mediator);

        virtual std::shared_ptr<unit> create(unit_enum type);

        ~unit_factory();
    };
}

#endif //LAB1_UNIT_FACTORY_H
