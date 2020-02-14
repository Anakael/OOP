#ifndef LAB1_LANDSCAPE_H
#define LAB1_LANDSCAPE_H

#include <objects/object.h>
#include <objects/units/unit_proxy.h>
#include <memory>

namespace game::field::landscape
{
    class landscape
    {
    protected:
        std::unique_ptr<game::object> object;
    public:
        virtual void affect_to_unit(units::unit_proxy& _unit_proxy) = 0;
        virtual ~landscape();
    };
}


#endif //LAB1_LANDSCAPE_H
