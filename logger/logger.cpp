#include "logger.h"
#include <fstream>

namespace logger
{
    logger& logger::operator<<(std::string _str)
    {
        *stream << _str;
        return *this;
    }

    logger::logger(std::ostream& _stream)
            : stream(&_stream)
    {
    }

    logger::logger(std::string _file_name)
            : stream(new std::ofstream(_file_name))
    {
    }

    logger::~logger()
    {
        auto* file$ = dynamic_cast<std::ofstream*>(stream);
        if (file$)
        {
            file$->close();
            delete file$;
        }
    }

    logger::logger()
    {
    }
}


