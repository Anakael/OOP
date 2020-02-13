#ifndef LAB1_PUBLISHER_H
#define LAB1_PUBLISHER_H

#include <vector>
#include <memory>

namespace game::units
{
    class unit;
}

namespace game
{
    class subscriber;
    class publisher
    {
    private:
        std::vector<std::reference_wrapper<subscriber>> subscribers;
    public:
        void add_subscriber(subscriber& _subscriber);

        void notify(const units::unit& _unit);
    };
}

#endif //LAB1_PUBLISHER_H
