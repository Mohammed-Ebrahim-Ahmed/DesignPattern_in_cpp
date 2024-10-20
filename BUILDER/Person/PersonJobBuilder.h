#pragma once
#include "iostream"
#include <string>
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase {
    public:
    typedef PersonJobBuilder Self;
    PersonJobBuilder(Person& person): PersonBuilderBase(person) {}

    Self& at(const std::string& street_address)
    {
        person.street_address = street_address;
        return *this;
    }

    Self& as_a(const std::string& position)
    {
    person.position = position;
    return *this;
    }

    Self& earning(int annual_income)
    {
    person.annual_income = annual_income;
    return *this;
    }    
};