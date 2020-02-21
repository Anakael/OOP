#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include <ostream>
#include <memory>
#include <string>

namespace logger
{
    class logger
    {
    private:
        std::ostream* stream = nullptr;
    public:
        logger();

        logger(std::string _file_name);

        logger(std::ostream& _stream);

        virtual logger& operator<<(std::string _str);

        ~logger();
    };
}

#endif //OOP_LOGGER_H
