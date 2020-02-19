#include "facade.h"
#include <field/field.h>
#include <commands/create_object_command.h>

namespace game
{
    facade::facade(int _length, int _width, int _max_count_of_objects)
    {
        field = std::make_unique<field::field>(field::field(_length, _width, _max_count_of_objects));
        mediator = std::make_unique<game::mediator>(game::mediator(*field));
        handlers_factory = std::make_unique<handlers::handlers_factory>(handlers::handlers_factory());
        handlers_factory->set_mediator(*mediator);
    }

    void facade::create_base(common::coordinates _to, int _max_count_of_units)
    {
        base = std::make_shared<game::base>(game::base(_max_count_of_units));
        base->set_mediator(*mediator);
        mediator->send(commands::create_object_command(*base, base, _to));
    }

    std::shared_ptr<object> facade::select_object(common::coordinates _coords)
    {
        auto obj = field->get(_coords).get_object();
        selected_object = obj;
        return obj;
    }

    std::shared_ptr<handlers::handler> facade::make_handler_for(common::coordinates _to)
    {
        return handlers_factory->create_handler(selected_object, _to);
    }
}


