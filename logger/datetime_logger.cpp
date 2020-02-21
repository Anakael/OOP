#include "datetime_logger.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>


namespace logger
{
    datetime_logger& datetime_logger::log(const std::string &_str)
    {
        using std::chrono::system_clock;
        std::time_t tt = system_clock::to_time_t(system_clock::now());
        auto ptm(std::localtime(&tt));
        *stream << std::put_time(ptm,"%c: ") << _str;
        return *this;
    }

    datetime_logger::datetime_logger(std::ostream& _stream)
            : stream(&_stream)
    {
    }

    datetime_logger::datetime_logger(std::string _file_name)
            : stream(new std::ofstream(_file_name))
    {
    }

    datetime_logger::~datetime_logger()
    {
        auto* file$ = dynamic_cast<std::ofstream*>(stream);
        if (file$)
        {
            file$->close();
            delete file$;
        }
    }

    datetime_logger::datetime_logger()
    {
    }
}

