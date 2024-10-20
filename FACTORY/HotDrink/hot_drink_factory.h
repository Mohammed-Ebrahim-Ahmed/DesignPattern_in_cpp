#pragma once
#include "hot_drink.h"
#include <memory>

struct HotDrinkFactory {

    virtual ~HotDrinkFactory() = default;
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {

    std::unique_ptr<HotDrink> make() const override {

        return std::make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory {

    std::unique_ptr<HotDrink> make() const override {

        return std::make_unique<Coffee>();
    }  
};