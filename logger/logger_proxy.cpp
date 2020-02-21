#include "logger_proxy.h"

namespace logger
{
    logger_proxy& logger_proxy::inst()
    {
        static logger_proxy instance;
        return instance;
    }
}


