#include "none_handler.h"
#include <iostream>
#include <utility>

namespace game::handlers
{
    none_handler::none_handler(std::string  _reason)
        : reason(std::move(_reason))
    {

    }
    void none_handler::handle()
    {
        std::cout << "Nothing target handle. Reason: " << reason << std::endl;
    }
}


