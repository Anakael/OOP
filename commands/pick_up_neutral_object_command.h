#ifndef OOP_PICK_UP_NEUTRAL_OBJECT_COMMAND_H
#define OOP_PICK_UP_NEUTRAL_OBJECT_COMMAND_H

#include "command.h"
#include <field/neutral_objects/neutral_objects/neutral_object.h>

namespace game::commands
{
    class pick_up_neutral_object_command : public command
    {
    private:
        field::neutral_objects::neutral_object& neutral_object;
    public:
        pick_up_neutral_object_command(object& sender, field::neutral_objects::neutral_object& _neutral_object);
        void operator()(field::field& _field) override;
    };
}



#endif //OOP_PICK_UP_NEUTRAL_OBJECT_COMMAND_H
