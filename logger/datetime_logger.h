#ifndef OOP_DATETIME_LOGGER_H
#define OOP_DATETIME_LOGGER_H

#include <ostream>
#include <memory>
#include <string>

namespace logger
{
    class datetime_logger
    {
    private:
        std::ostream* stream = nullptr;
    public:
        datetime_logger();

        datetime_logger(std::string _file_name);

        datetime_logger(std::ostream& _stream);

        datetime_logger& log(const std::string &_str);

        ~datetime_logger();
    };
}

#endif //OOP_DATETIME_LOGGER_H
