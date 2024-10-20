#pragma once
#include <string>
#include <iostream>


class PersonBuilder;
class PersonJobBuilder;
class PersonAddressBuilder;

class Person{
private:
    // address
    std::string street_address, post_code, city;
    // employment
    std::string company_name, position;
    int annual_income{0};
    Person() = default;
public:
    ~Person() = default;

    static PersonBuilder create() ;
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

    friend std::ostream& operator <<(std::ostream& out, Person& person)
    {
        return out << person.street_address << " "
        << person.post_code << " " << person.city << std::endl
        << person.company_name << " " << person.position << std::endl;
    }
  Person(Person&& other)
    : street_address{std::move(other.street_address)},
      post_code{std::move(other.post_code)},
      city{std::move(other.city)},
      company_name{std::move(other.company_name)},
      position{std::move(other.position)},
      annual_income{other.annual_income}
  {
  }

  Person& operator=(Person&& other)
  {
    if (this == &other)
      return *this;
    street_address = std::move(other.street_address);
    post_code = std::move(other.post_code);
    city = std::move(other.city);
    company_name = std::move(other.company_name);
    position = std::move(other.position);
    annual_income = other.annual_income;
    return *this;
  }
};