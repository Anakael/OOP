#ifndef OOP_NONE_HANDLER_H
#define OOP_NONE_HANDLER_H

#include "handler.h"

namespace game::handlers
{
    class none_handler : public handler
    {
    private:
        const std::string reason;
    public:
        none_handler(std::string  _reason);
        void handle() override;
    };
}

#endif //OOP_NONE_HANDLER_H
