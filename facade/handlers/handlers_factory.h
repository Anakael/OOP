#ifndef OOP_HANDLERS_FACTORY_H
#define OOP_HANDLERS_FACTORY_H

#include <objects/object.h>
#include <mediator/component.h>
#include "handler.h"
#include <common/coordinates.h>

namespace game::handlers
{
    class handlers_factory : public component
    {
    public:
        std::shared_ptr<handlers::handler>
        create_handler(std::shared_ptr<object> selected_object, common::coordinates _to);
    };
}


#endif //OOP_HANDLERS_FACTORY_H
