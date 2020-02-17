#ifndef LAB1_BASE_H
#define LAB1_BASE_H

#include <objects/object.h>
#include <objects/units/unit_factory.h>
#include <observer/subscriber.h>
#include <common/coordinates.h>
#include <vector>
#include <memory>

namespace game
{
    class base : public object, public subscriber
    {
    private:
        std::unique_ptr<game::units::unit_factory> factory;
        std::vector<std::reference_wrapper<units::unit>> units;
        int max_units_count;
    public:
        base(mediator& mediator, int _max_units_count, int health, int _armor_point);

        int get_max_units_count()
        { return max_units_count; }

        void set_max_units_count(int _max_units_count)
        { max_units_count = _max_units_count; }

        std::shared_ptr<game::units::unit> create_unit(unit_enum type, common::coordinates _to);

        void update(const units::unit& _unit) override;
    };
}

#endif //LAB1_BASE_H
