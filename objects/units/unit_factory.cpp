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

game::units::unit_factory::~unit_factory()
{

}

namespace game::units
{
    std::unique_ptr<unit> game::units::unit_factory::create(unit_enum type)
    {
        using namespace warriors;
        using namespace mages;
        using namespace shooters;
        switch (type)
        {
            case unit_enum::FOOTMAN:
                return std::make_unique<warrior>(footman());
            case unit_enum::KNIGHT:
                return std::make_unique<warrior>(knight());
            case unit_enum::ARCHER:
                return std::make_unique<shooter>(archer());
            case unit_enum::RIFLEMAN:
                return std::make_unique<shooter>(rifleman());
            case unit_enum::PRIEST:
                return std::make_unique<mage>(priest());
            case unit_enum::SOURCERER:
                return std::make_unique<mage>(soucerer());
            default:
                return nullptr;
        }
    }
}


