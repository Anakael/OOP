#ifndef OOP_SAVE_LOAD_COMMAND_H
#define OOP_SAVE_LOAD_COMMAND_H

#include <map>
#include <field/field.h>
#include <memory>
#include <objects/base/base.h>
#include <fstream>
#include <iostream>

namespace save_load
{
    class save_load_command
    {
    protected:
        std::vector<std::reference_wrapper<game::base>> bases;
        std::shared_ptr<game::field::field> field;
        std::string file_name;
        unsigned int CRC32_function(unsigned char* buf, unsigned long len);
        unsigned int CRC32_count(const std::string& _file_name);

    public:
        explicit save_load_command(std::shared_ptr<game::field::field> _field, std::string _file_name);

        virtual void operator()() = 0;
    };
}


#endif //OOP_SAVE_LOAD_COMMAND_H
