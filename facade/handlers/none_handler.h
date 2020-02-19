#ifndef OOP_NONE_HANDLER_H
#define OOP_NONE_HANDLER_H

#include "handler.h"

namespace game::handlers
{
    class none_handler : public handler
    {
    public:
        void handle() override;
    };
}

#endif //OOP_NONE_HANDLER_H
