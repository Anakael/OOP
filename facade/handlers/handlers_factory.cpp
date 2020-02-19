#include "handlers_factory.h"
#include <objects/units/unit_factory.h>
#include "none_handler.h"
#include "attack_handler.h"
#include "move_handler.h"
#include "create_unit_handler.h"
#include <objects/units/unit.h>
#include <objects/units/unit_proxy.h>
#include <objects/base/base.h>

namespace game::handlers
{
    std::shared_ptr<handlers::handler>
    handlers_factory::create_handler(std::shared_ptr<object> _selected_object, common::coordinates _to)
    {
        if (!_selected_object)
        {
            return std::make_shared<none_handler>();
        }
        auto cell_to = mediator_ref->get_cell(_to);
        auto* unit$ = dynamic_cast<units::unit*>(_selected_object.get());
        if (unit$)
        {
            auto unit_proxy = units::unit_proxy(*unit$);
            auto coords_from = _selected_object->get_coords();
            cell_to.get_landscape()->affect_to_unit(unit_proxy);
            mediator_ref->get_cell(coords_from).get_landscape()->affect_to_unit(unit_proxy);

            if (cell_to.get_object())
            {
                bool enough_distance = coords_from.distance_to(_to) <= unit$->get_attack_attribute().get_attack_range();
                if (unit_proxy.get_can_attack_from() && enough_distance)
                {
                    return std::make_shared<attack_handler>(*unit$, _to);
                }
            }
            if (unit_proxy.get_can_move_to())
            {
                bool enough_distance = true; // TODO: add speed attrib
                return std::make_shared<move_handler>(*unit$, _to);
            }
        }

        auto* base$ = dynamic_cast<base*>(_selected_object.get());
        if (base$)
        {
            auto selected_unit = base$->get_selected_unit();
            if (selected_unit.has_value())
            {
                if (base$->get_units_count() + 1 > base$->get_max_units_count())
                {
                    return std::make_shared<none_handler>();
                    //std::cout << "Max count of units reached" << std::endl;
                }

                if (mediator_ref->get_coords(*base$).distance_to(_to) > 1)
                {
                    //std::cout << "Max much distance" << std::endl;
                    return std::make_shared<none_handler>();
                }
                units::unit_factory temp_factory(*mediator_ref);
                auto temp_unit = temp_factory.create(selected_unit.value());
                auto unit_proxy = units::unit_proxy(*temp_unit);
                cell_to.get_landscape()->affect_to_unit(unit_proxy);
                if (unit_proxy.get_can_move_to())
                {
                    return std::make_shared<create_unit_handler>(*base$, _to);
                }
            }
        }

        return std::make_shared<none_handler>();
    }
}


