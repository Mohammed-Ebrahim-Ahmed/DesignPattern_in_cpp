#include <iostream>
#include <memory>
#include <initializer_list>
#include <utility>
#include <sstream>
#include <vector>

struct Tag{

    std::string name;
    std::string text;
    std::vector<Tag> childrens;
    std::vector<std::pair<std::string, std::string>> attributes;

    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
    {
      os << "<" << tag.name;

      for (const auto& att : tag.attributes)
        os << " " << att.first << "=\"" << att.second << "\"";

      if (tag.childrens.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      } 
      else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.childrens)
          os << child;

        os << "</" << tag.name << ">" << std::endl;
      }

      return os;
    }
    protected:
    Tag(const std::string& name, const std::string& text) : name{name}, text{text} {}
    Tag(const std::string& name, const std::vector<Tag>& childrens): name{name}, childrens{childrens} {}
};

class Para : public Tag {
    public:
    Para(const std::string& text): Tag("P", text) {}
    Para(std::initializer_list<Tag> children): Tag("P", children) {}
};

class Img : public Tag{
    public:
    explicit Img(const std::string& url) : Tag("Img", "")
    {
        attributes.emplace_back(std::make_pair("src", "url"));
    }
};


int main()
{
    std::cout << Para{{Img{"https://pokemon.com/pikachu.png"}, Img{"https://fun.com"}}} << std::endl;
}