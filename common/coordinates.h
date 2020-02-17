#ifndef OOP_COORDINATES_H
#define OOP_COORDINATES_H

#include <cmath>

namespace common
{
    struct coordinates
    {
        int x = 0;
        int y = 0;

        coordinates()
        = default;

        coordinates(int _x, int _y)
                : x(_x), y(_y)
        {
        }

        int distance_to(coordinates& other)
        {
            return floor(sqrt(pow(other.x - x, 2) + pow(other.y - x, 2)));
        }
    };
}

#endif //OOP_COORDINATES_H
