#pragma once
#include "hot_drink.h"
#include "hot_drink_factory.h"
#include <map>
#include <functional>

class DrinkFactory{
private: 
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> HotFactory;

public:  
    DrinkFactory()
    {
        HotFactory["Tea"] = std::make_unique<TeaFactory>();
        HotFactory["Coffee"] = std::make_unique<CoffeeFactory>();
    }


    std::unique_ptr<HotDrink> make_drink(const std::string& name)
    {
        auto drink = HotFactory[name]->make();
        drink->prepare(200);
        return drink;
    }
};

class DrinkWithVolumeFactory{

    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:  

    DrinkWithVolumeFactory()
    {
        factories["Tea"] = [](){
            auto tea = std::make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories["Coffee"] = [](){
            auto coffee = std::make_unique<Coffee>();
            coffee->prepare(200);
            return coffee;
        };
    }

    std::unique_ptr<HotDrink> make_drink(std::string name)
    {
        return factories[name]();
    }
};