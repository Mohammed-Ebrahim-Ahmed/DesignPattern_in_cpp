#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <string>

struct Person;

struct RelationShipBrowser 
{
    virtual std::vector<Person> find_all_children_of(const std::string& name) = 0;
};

enum class Relationship{
    parent,
    child,
    siblingh
};

struct Person{
    std::string name;
};

struct Relationships :RelationShipBrowser // low level
{
    std::vector<std::tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    std::vector<Person> find_all_children_of(const std::string& name) override {
        std::vector<Person> result;
        for(auto&& [first, rel, second] : relations)
        {
            if(first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research // high level module
{
    // Research(Relationship& relationships)
    // {
    //     auto relations& = relationships.relations;

    //     for(auto&& [first, rel, second] : relations)
    //     {
    //         if(first.name == "John" && rel ==  Relationship::parent )
    //         {
    //             std::cout << "John has a child called" >> std::endl;
    //         }
    //     }
    // }

    Research(RelationShipBrowser& browser)
    {
        for(auto& child : browser.find_all_children_of("John"))
        {
            std::cout << "John has a child called " << child.name << std::endl;
        }
    } 
};
int main()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
    return 0;
}