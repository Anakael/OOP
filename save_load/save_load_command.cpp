#include "save_load_command.h"

#include <utility>
#include <fstream>

namespace save_load
{
    save_load_command::save_load_command(std::shared_ptr<game::field::field> _field, std::string _file_name)
            : field(std::move(_field)), file_name(std::move(_file_name))
    {

    }

    unsigned int save_load_command::CRC32_function(unsigned char* buf, unsigned long len)
    {
        unsigned long crc_table[256];
        unsigned long crc;
        for (int i = 0; i < 256; i++)
        {
            crc = i;
            for (int j = 0; j < 8; j++)
                crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
            crc_table[i] = crc;
        };
        crc = 0xFFFFFFFFUL;
        while (len--)
            crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
        return crc ^ 0xFFFFFFFFUL;
    }

    unsigned int save_load_command::CRC32_count(const std::string& filename)
    {
        char buf[4096 * 64];
        std::ifstream f(filename, std::ios::binary);
        f.seekg(sizeof(unsigned int), f.beg);
        f.read(buf, 4096 * 64);
        return CRC32_function((unsigned char*) buf, f.gcount());
    }
}
