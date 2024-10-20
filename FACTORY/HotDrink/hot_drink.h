#pragma once
#include <iostream>
#include <string>


class HotDrink{

public:
    virtual ~HotDrink() = default;

    virtual void prepare(int volume) = 0;

};


class Tea : public HotDrink {

public:

    void prepare(int volume) override
    {
        std::cout << "we prepare Tea with volume" << volume << std::endl;
    }
};

class Coffee : public HotDrink {

public:

    void prepare(int volume) override
    {
        std::cout << "we prepare Coffee with volume" << volume << std::endl;
    }
};