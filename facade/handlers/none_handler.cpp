#include "none_handler.h"
#include <iostream>

namespace game::handlers
{
    void none_handler::handle()
    {
        std::cout << "Nothing to handle" << std::endl;
    }
}


