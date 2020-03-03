#include "cell.h"
#include "landscape/plain/plain.h"
#include "landscape/hill/hill.h"
#include "landscape/water/water.h"
#include <objects/base/base.h>
#include <objects/units/warriors/footman/footman.h>
#include <objects/units/warriors/knight/knight.h>
#include <objects/units/shooters/archer/archer.h>
#include <objects/units/shooters/rifleman/rifleman.h>
#include <objects/units/mages/priest/priest.h>
#include <objects/units/mages/sourcerer/soucerer.h>

namespace game::field
{
    void cell::delete_object()
    {
        object.reset();
    }

    cell::cell()
    = default;

    void cell::swap(cell& first, cell& second)
    {
        using std::swap;
        swap(first.landscape, second.landscape);
        swap(first.object, second.object);
    }

    void cell::set_object(std::shared_ptr<game::object> _object)
    {
        object = std::move(_object);
    }

    std::shared_ptr<save_load::memento> cell::save()
    {
        std::shared_ptr<object::object_memento> object_momento = nullptr;
        if (object)
        {
            object_momento = std::static_pointer_cast<object::object_memento>(object->save());
        }
        return std::make_shared<cell_memento>(typeid(*landscape), object_momento);
    }

    void cell::restore(std::shared_ptr<save_load::memento> _memento)
    {
        auto memento = std::static_pointer_cast<cell_memento>(_memento);

        if (auto _landscape = cell::try_init_landscape<landscape::plain>(*memento))
        {
            landscape = _landscape ? _landscape : landscape;
        }
        else if (auto _landscape = cell::try_init_landscape<landscape::hill>(*memento))
        {
            landscape = _landscape ? _landscape : landscape;
        }
        else if (auto _landscape = cell::try_init_landscape<landscape::water>(*memento))
        {
            landscape = _landscape ? _landscape : landscape;
        }

        if (memento->object == nullptr)
        {
            object = nullptr;
            return;
        }
        if (auto _object = cell::try_init_object<base>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::warriors::footman>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::warriors::knight>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::shooters::archer>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::shooters::rifleman>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::mages::priest>(*memento))
        {
            object = _object ? _object : object;
        }
        else if (auto _object = cell::try_init_object<units::mages::soucerer>(*memento))
        {
            object = _object ? _object : object;
        }

        object->restore(memento->object);
    }
}
