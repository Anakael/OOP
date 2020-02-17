#include "unit_factory.h"
#include "warriors/warrior.h"
#include "shooters/shooter.h"
#include "mages/mage.h"
#include "warriors/footman/footman.h"
#include "warriors/knight/knight.h"
#include "shooters/archer/archer.h"
#include "shooters/rifleman/rifleman.h"
#include "mages/priest/priest.h"
#include "mages/sourcerer/soucerer.h"


namespace game::units
{
    std::shared_ptr<unit> game::units::unit_factory::create(unit_enum type)
    {
        using namespace warriors;
        using namespace mages;
        using namespace shooters;
        auto new_unit = std::shared_ptr<unit>();
        switch (type)
        {
            case unit_enum::FOOTMAN:
                new_unit = std::make_shared<footman>(footman());
                break;
            case unit_enum::KNIGHT:
                new_unit = std::make_shared<knight>(knight());
                break;
            case unit_enum::ARCHER:
                new_unit = std::make_shared<archer>(archer());
                break;
            case unit_enum::RIFLEMAN:
                new_unit = std::make_shared<rifleman>(rifleman());
                break;
            case unit_enum::PRIEST:
                new_unit = std::make_shared<priest>(priest());
                break;
            case unit_enum::SOURCERER:
                new_unit = std::make_shared<soucerer>(soucerer());
                break;
            default:
                return nullptr;
        }
        new_unit->set_mediator(*mediator_ref);
        return new_unit;
    }

    unit_factory::unit_factory(mediator& _mediator)
    {
        mediator_ref = &_mediator;
    }

    game::units::unit_factory::~unit_factory()
    = default;
}


