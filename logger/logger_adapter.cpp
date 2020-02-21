#include "logger_adapter.h"

namespace logger
{
    logger_adapter::logger_adapter(datetime_logger&& _logger)
        : date_logger(&_logger)
    {
    }

    logger& logger_adapter::operator<<(std::string _str)
    {
        date_logger->log(std::move(_str));
        return *this;
    }
}


