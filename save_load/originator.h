#ifndef OOP_ORIGINATOR_H
#define OOP_ORIGINATOR_H

#include <memory>
#include "memento.h"

namespace save_load
{
    class originator
    {
    public:
        virtual std::shared_ptr<memento> save() = 0;

        virtual void restore(std::shared_ptr<memento> _imemento) = 0;

        virtual ~originator() = default;
    };
}

#endif //OOP_ORIGINATOR_H
