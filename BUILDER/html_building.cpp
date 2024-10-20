#include <sstream>
#include <memory>
#include <array>
#include <iostream>

int main()
{
    auto text = "hello";
    std::string output;
    output += "<p>";
    output += "text";
    output += "</p>";

    std::cout << output << std::endl;
    std::array<std::string, 2> words = {"hello", "world"};

    std::ostringstream oss;

    oss << "<ul>";
    for(auto w: words)
    {
        oss << " <li>" << w << "</li>";
    }
    oss << "</ul>";
    std::cout << oss.str() << std::endl;
    return 0;
}