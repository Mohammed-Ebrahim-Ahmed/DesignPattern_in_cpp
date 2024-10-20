#pragma once

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase{
protected:
    Person& person;

    explicit PersonBuilderBase(Person& person): person{person} {}

public:
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
    operator Person() const{
        return std::move(person);
    }
};


class PersonBuilder : public PersonBuilderBase {
public:
    Person person;

    PersonBuilder(): PersonBuilderBase(person) {}
};