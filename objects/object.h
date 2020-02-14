#ifndef LAB1_OBJECT_H
#define LAB1_OBJECT_H

namespace game
{
    class object
    {
    protected:
        int max_health = 0;
        int health = 0;
        int defend_point = 0;

    public:
        object();

        object(int _max_health, int _defend_point);

        int get_health()
        { return health; }

        int get_defend_point()
        { return defend_point; }
    };
}

#endif //LAB1_OBJECT_H
