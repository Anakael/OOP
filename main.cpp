#include <iostream>

#include <facade/facade.h>
#include <common/coordinates.h>

int main()
{
    using namespace game;
    auto facade = game::facade(10, 10, 100);
    facade.create_base(common::coordinates(0, 0), 10);
    auto& base = dynamic_cast<game::base&>(*facade.select_object(common::coordinates(0, 0)));
    base.select_unit_to_create(unit_enum::PRIEST);
    auto handler = facade.make_handler_for(common::coordinates(1,1));
    handler->handle();
    std::cout << facade.select_object({1, 1}) << std::endl;
    auto tree = base.get_tree_view();
    return 0;
}
