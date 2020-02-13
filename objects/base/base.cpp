#include "base.h"
#include <iostream>

namespace game::base
{
    game::base::base::base(int _max_units_count)
            : max_units_count(_max_units_count)
    {
        factory = std::make_unique<units::unit_factory>();
    }

    std::unique_ptr<units::unit> base::create_unit(unit_enum type)
    {
        if (units.size() + 1 <= max_units_count)
        {
            auto new_unit = factory->create(type);
            units.emplace_back(*new_unit);
            new_unit->add_subscriber(*this);
            return new_unit;
        }
        else
        {
            std::cout << "Max count of units reached" << std::endl;
        }
        return nullptr;
    }

    void base::update(const game::units::unit& _object)
    {
        using namespace units;
        units.erase(std::remove_if(units.begin(), units.end(), [_object](const auto& x){return x.get() == _object;}), units.end());
    }
}



