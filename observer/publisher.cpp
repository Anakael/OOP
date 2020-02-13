#include "publisher.h"
#include "subscriber.h"

namespace game
{
    void publisher::add_subscriber(subscriber& _subscriber)
    {
        subscribers.emplace_back(_subscriber);
    }

    void publisher::notify(const units::unit& _unit)
    {
        for (auto& it : subscribers)
            it.get().update(_unit);
    }
}


