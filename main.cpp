#include <iostream>

#include <facade/facade.h>
#include <common/coordinates.h>
#include <logger/logger.h>
#include <logger/logger_proxy.h>
#include <fstream>

int main()
{
    using namespace game;
    logger::logger_proxy::inst().set_logger(std::move(*new logger::logger(std::cout)));
    // auto adapter = logger::logger_adapter(std::move(*new logger::datetime_logger(std::cout)));
    // adapter << "LOL";

    auto facade = game::facade(2, 2, 4);
    facade.create_base(common::coordinates(0, 0), 10);

    auto& base = dynamic_cast<game::base&>(*facade.select_object(common::coordinates(0, 0)));
    base.select_unit_to_create(unit_enum::PRIEST);
    auto handler = facade.make_handler_for(common::coordinates(1, 1));
    handler->handle();
    facade.save("1.save");
    facade.load("1.save");
    base.select_unit_to_create(unit_enum::KNIGHT);
    handler = facade.make_handler_for(common::coordinates(0, 1));
    handler->handle();
    std::cout << facade.select_object({1, 1})->get_health() << std::endl;
    auto tree = base.get_tree_view();
    facade.select_object({0, 1});
    handler = facade.make_handler_for({1, 1});

    for (int i = 0; i < 25; ++i)
    {
        if (facade.select_object({1, 1}))
        {
            handler->handle();
            if (facade.select_object({1, 1}))
            {
                std::cout << facade.select_object({1, 1})->get_health() << std::endl;
            }
            else
            {
                std::cout << "DEAD" << std::endl;
                break;
            }
        }

    }

    return 0;
}
