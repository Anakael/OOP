#ifndef OOP_LOGGER_ADAPTER_H
#define OOP_LOGGER_ADAPTER_H

#include "logger.h"
#include "datetime_logger.h"

namespace logger
{
    class logger_adapter : public logger
    {
    private:
        std::unique_ptr<datetime_logger> date_logger;
    public:
        logger_adapter(datetime_logger&& _logger);

        logger& operator<<(std::string _str) override;
    };
}

#endif //OOP_LOGGER_ADAPTER_H
