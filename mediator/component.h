#ifndef OOP_COMPONENT_H
#define OOP_COMPONENT_H

#include <memory>
#include <utility>

namespace game
{
    class mediator;

    class component
    {
    protected:
        mediator* mediator_ref = nullptr;
    public:
        void set_mediator(mediator& _mediator)
        { mediator_ref = &_mediator; }

        virtual ~component() = 0;
    };
}

#endif //OOP_COMPONENT_H
