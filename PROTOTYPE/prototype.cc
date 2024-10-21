#include <iostream>
#include <memory>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
using namespace boost;

class Address{
public:  
    std::string street, city;
    int suite;
    Address() = default;
    Address(const std::string& street, const std::string& city, int suite): street{street}, city{city}, suite{suite} {}

    Address(const Address& other): street{other.street}, city{other.city}, suite{other.suite} {}

    friend class serialization::access;

    template<class archive>
    void serialize(archive& ar, const unsigned version)
    {
        ar & street;
        ar & city;
        ar & suite;
    }    
};

class Contact {
public:  
    std::string name;
    Address *address;

    Contact()= default;
    Contact(const std::string& name, Address* address) : name{name}, address{address} {}

    Contact(const Contact& other): name{name}, address{ new Address{*other.address}} {}

    friend std::ostream& operator<<(std::ostream& out, Contact& contact)
    {
        return out << contact.name << " " << contact.address->street << " " << contact.address->city << " " << contact.address->suite << std::endl;
    }

    friend class serialization::access;

    template<class archive>
    void serialize(archive& ar, const unsigned version)
    {
        ar & name;
        ar & address;
    }
};

class EmployeeFactory{
public:  

    static std::unique_ptr<Contact> new_main_office_employee(const std::string& name, const int suite)
    {
        static Contact con{name, new Address{"123 East Dr", "London", suite}};
        return std::make_unique<Contact>(con);
    }
private: 

};

int main()
{
    // Contact John{"John Doe", new Address{"123 East Dr", "London", 123}};
    // Contact Jane{John};
    // Jane.name = "Jane Smith";
    // Jane.address->suite = 103;
    // std::cout << John;
    // std::cout << Jane;

    // auto contact_ptr = EmployeeFactory{}.new_main_office_employee("ahmed", 345);

    // std::cout << *contact_ptr;

    auto clone = [](const Contact& c){
        // serialize here
        std::ostringstream oss;
        archive::text_oarchive oa(oss);
        oa << c;
        std::string s = oss.str();
        std::cout << s << std::endl;

        // Deserialize

        std::istringstream iss{s};
        archive::text_iarchive ia(iss);
        Contact result{};
        ia >> result;
        return result;
    };

    auto e_ptr = EmployeeFactory::new_main_office_employee("mohammed", 2);

    std::cout << *e_ptr;
    auto John = clone(*e_ptr);

    John.name = "John harber";

    John.address->suite = 7;

    std::cout << John;

}