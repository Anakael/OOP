#ifndef LAB1_UNIT_PROXY_H
#define LAB1_UNIT_PROXY_H

#include "unit.h"
#include <memory>
#include <typeindex>

namespace game::units
{
    class unit_proxy : public unit
    {
    private:
        bool can_move_to = true;
        bool can_attack_from = true;
        unit& internal_unit;
    public:
        explicit unit_proxy(unit& _unit);

        std::type_index get_type_of_inner_unit();

        void set_can_move_to(bool flag)
        { can_move_to = flag; }

        void set_can_attack_from(bool flag)
        { can_attack_from = flag; }

        void move_to(int x, int y) override;
    };
}

#endif //LAB1_UNIT_PROXY_H
