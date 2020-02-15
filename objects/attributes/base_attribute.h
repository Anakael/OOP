#ifndef LAB1_BASE_ATTRIBUTE_H
#define LAB1_BASE_ATTRIBUTE_H

namespace game::attributes
{
    class base_attribute
    {
    protected:
        int value = 0;
    public:
        int get_value() const
        { return value; }

        base_attribute(int _value);

        virtual void decrease(int _value);

        virtual void increase(int _value);
    };
}

#endif //LAB1_BASE_ATTRIBUTE_H
