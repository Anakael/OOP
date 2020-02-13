#ifndef LAB1_OBJECT_H
#define LAB1_OBJECT_H

namespace game
{
    class object
    {
    protected:
        int health;
        int defend_point;

    public:
        object();

        object(int _health, int _defend_point);

        int get_health()
        { return health; }

        int get_defend_point()
        { return defend_point; }
    };
}

#endif //LAB1_OBJECT_H
