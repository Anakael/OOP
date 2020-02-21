#include "facade.h"
#include <logger/logger_proxy.h>
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
        logger::logger_proxy::inst() << "Base created at coordinates" << _to  << "With max count of objects: " << std::to_string(_max_count_of_units) << "\n";
    }

    std::shared_ptr<object> facade::select_object(common::coordinates _coords)
    {
        auto obj = field->get(_coords).get_object();
        logger::logger_proxy::inst() << "Select object at coordinates: " << _coords;
        selected_object = obj;
        return obj;
    }

    std::shared_ptr<handlers::handler> facade::make_handler_for(common::coordinates _to)
    {
        auto handler = handlers_factory->create_handler(selected_object, _to);
        logger::logger_proxy::inst() << "Create handler for coordinates: " << _to;
        return handler;
    }
}


