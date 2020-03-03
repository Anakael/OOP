#ifndef OOP_FACADE_H
#define OOP_FACADE_H

#include <field/field.h>
#include <objects/base/base.h>
#include <common/coordinates.h>
#include "handlers/handler.h"
#include "handlers/handlers_factory.h"
#include <memory>
#include <mediator/mediator.h>

namespace game
{
    class facade
    {
    private:
        std::shared_ptr<field::field> field;
        std::unique_ptr<mediator> mediator;
        std::unique_ptr<handlers::handlers_factory> handlers_factory;
        std::shared_ptr<game::base> base;
        std::shared_ptr<object> selected_object;
    public:
        facade(int _length, int _width, int _max_count_of_objects);

        void create_base(common::coordinates _to, int _max_count_of_units);

        std::shared_ptr<object> select_object(common::coordinates _coords);

        std::shared_ptr<handlers::handler> make_handler_for(common::coordinates _to);

        void save(const std::string& _out);

        void load(const std::string& _in);
    };
}

#endif //OOP_FACADE_H
