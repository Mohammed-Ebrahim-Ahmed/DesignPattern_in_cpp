#include "hot_drink_factory.h"
#include "drink_factory.h"
std::unique_ptr<HotDrink> make_drink(const std::string& type)
{
    std::unique_ptr<HotDrink> drink;

    if(type == "Tea")
    {
        drink = std::make_unique<Tea>();
        drink->prepare(200);
    }
    else {
        drink = std::make_unique<Coffee>();
        drink->prepare(200);
    }
    return drink;
}


int main()
{

    // DrinkFactory{}.make_drink("Tea");

    DrinkWithVolumeFactory{}.make_drink("Coffee");
    return 0;
}