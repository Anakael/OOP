#ifndef OOP_LOGGER_PROXY_H
#define OOP_LOGGER_PROXY_H

#include "logger.h"
#include <memory>
#include <sstream>

namespace logger
{
    class logger_proxy : public logger
    {
    private:
        std::unique_ptr<logger> inner_logger;
    public:
        static logger_proxy& inst();
        void set_logger(logger&& _logger)
        { inner_logger.reset(&_logger); }

        template<typename T>
        logger_proxy& operator<<(const T &t)
        {
            if (inner_logger)
            {
                std::stringstream ss;
                ss << t;
                *inner_logger << ss.str();
            }
            return *this;
        }
    };
}

#endif //OOP_LOGGER_PROXY_H
