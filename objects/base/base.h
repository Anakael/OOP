#ifndef LAB1_BASE_H
#define LAB1_BASE_H

#include <objects/object.h>
#include <objects/units/unit_factory.h>
#include <observer/subscriber.h>
#include <vector>
#include <memory>

namespace game::base
{
    class base : public object, public subscriber
    {
    private:
        std::unique_ptr<game::units::unit_factory> factory;
        std::vector<std::reference_wrapper<units::unit>> units;
        int max_units_count;
    public:
        base(int _max_units_count);

        int get_max_units_count()
        { return max_units_count; }

        void set_max_units_count(int _max_units_count)
        { max_units_count = _max_units_count; }

        std::unique_ptr<game::units::unit> create_unit(unit_enum type);

        virtual void update(const units::unit& _unit) override;
    };
}

#endif //LAB1_BASE_H
