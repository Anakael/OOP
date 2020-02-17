#ifndef OOP_COMMAND_H
#define OOP_COMMAND_H

#include <cstddef>
#include <objects/object.h>
#include <field/field.h>

namespace game::commands
{
    class command
    {
    protected:
        object& sender;
    public:
        command(object& _sender);

        object& get_sender() const { return sender; }

        virtual void operator()(field::field& _field) = 0;
    };
}

#endif //OOP_COMMAND_H
