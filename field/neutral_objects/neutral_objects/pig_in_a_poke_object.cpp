#include "pig_in_a_poke_object.h"
#include <memory>
#include <field/neutral_objects/strategies/healing_strategy.h>
#include <field/neutral_objects/strategies/restoring_strategy.h>
#include <field/neutral_objects/strategies/strengthening_strategy.h>
#include <field/neutral_objects/strategies/killing_strategy.h>
#include <random>

namespace game::field::neutral_objects
{
    pig_in_a_poke_object::pig_in_a_poke_object()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::discrete_distribution<> dis({4,2,3,1});
        std::unique_ptr<strategies::neutral_object_affect_strategy> strategy;
        switch (dis(mt))
        {
            case 0:
                strategy = std::make_unique<strategies::healing_strategy>(strategies::healing_strategy());
                break;
            case 1:
                strategy = std::make_unique<strategies::restoring_strategy>(strategies::restoring_strategy());
                break;
            case 2:
                strategy = std::make_unique<strategies::strengthening_strategy>(strategies::strengthening_strategy());
                break;
            case 3:
                strategy = std::make_unique<strategies::killing_strategy>(strategies::killing_strategy());
                break;
        }
        set_strategy(std::move(*strategy.release()));
    }
}
