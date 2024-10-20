#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

struct HtmlBuilder;

class HtmlElement{
    friend class HtmlBuilder;
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    static constexpr int indent_size = 2;
    HtmlElement(const std::string& name, const std::string text): name{name}, text{text} {}
    HtmlElement() = default;
    public:
    std::string str(int indent = 0) const noexcept{

        std::ostringstream oss;
        std::string i(static_cast<size_t>(indent_size * indent), ' ');
        oss << i << "<" << name << ">" << std::endl;
        if(text.size() > 0)
        {
            oss << std::string(static_cast<size_t>(indent_size*(indent+1)), ' ') << text << std::endl;
        }

        for(const auto & e: elements)
        {
            oss << e.str(indent + 1) << std::endl;
        }

        oss << i << "</" << name << ">";
        return oss.str();
    }
    static HtmlBuilder create(std::string root_name);
    static std::unique_ptr<HtmlBuilder> create2(std::string root_name);

    // {
    //     return HtmlBuilder{root_name};
    // }

};

struct HtmlBuilder{

    HtmlElement root;

    HtmlBuilder(std::string root_name){
        root.name = root_name;
    }
    HtmlBuilder& add_child(std::string child_name, std::string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    HtmlBuilder* add_child2(std::string child_name, std::string child_text)
    {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this;
    }
    std::string str()const noexcept {
        return root.str();
    }
    const HtmlElement& build() const noexcept
    {
        return root;
    }
    std::unique_ptr<HtmlElement> build2() const noexcept{
        return std::make_unique<HtmlElement>(root);
    }
    operator HtmlElement() const {
        return root;
    }
};

// Implement HtmlElement::create now that HtmlBuilder is fully defined
HtmlBuilder HtmlElement::create(std::string root_name) {
    return HtmlBuilder{root_name};
}

std::unique_ptr<HtmlBuilder> HtmlElement::create2(std::string root_name) {
    return std::make_unique<HtmlBuilder>(HtmlBuilder{root_name});
}
int main()
{
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello");
    builder.add_child("li", "world");

    HtmlBuilder builder2{"ul"};
    builder2.add_child("ll", "when").add_child("ff", "wow");

    HtmlElement ele = HtmlElement::create2("nn")->add_child2("dd", "func")->add_child("ss", "nice");
    // std::cout << ele.str();
    HtmlElement myele = HtmlElement::create2("list")->add_child("ii", "my name is mohammed").add_child("li"," i am 24 years old.").build();
    std::cout << myele.str();
   // std::cout << builder.str() << std::endl;
}