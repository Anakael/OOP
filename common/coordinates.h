#ifndef OOP_COORDINATES_H
#define OOP_COORDINATES_H

#include <cmath>
#include <ostream>

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

        int distance_to(const coordinates& other)
        {
            return floor(sqrt(pow(other.x - x, 2) + pow(other.y - x, 2)));
        }


        friend std::ostream& operator<<(std::ostream& os, const coordinates& coords)
        {
            os << "{x:" << coords.x << ";" << "y:" << coords.y << "}" << std::endl;
            return os;
        }
    };
}

#endif //OOP_COORDINATES_H
