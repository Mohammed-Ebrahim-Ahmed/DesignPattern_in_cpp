#include <string>
#include <vector>
#include <iostream>

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter {

    std::vector<Product*> by_color(std::vector<Product*> items, Color color)
    {
        std::vector<Product*> result;

        for(auto & i : items )
        {
            if(i->color == color)
            {
                result.push_back(i);
            }
        }
        return result;
    }
    std::vector<Product*> by_size(std::vector<Product*> items, Size size)
    {
        std::vector<Product*> result;

        for(auto & i : items )
        {
            if(i->size == size)
            {
                result.push_back(i);
            }
        }
        return result;
    }
    std::vector<Product*> by_color_and_size(std::vector<Product*> items, Color color ,Size size)
    {
        std::vector<Product*> result;

        for(auto & i : items )
        {
            if(i->size == size && i->color == color)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

template <typename T> struct AndSpecification;

template <typename T> 
struct Specification{
    virtual bool is_statisfied(T* item) = 0;
    AndSpecification<T> operator&&(Specification<T> &&other)
    {
        return AndSpecification<T>{*this, other};
    }
};

template <typename T>
struct Filter{
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T> & Spec) = 0;
};

struct BetterFilter : Filter<Product>{
    
    std::vector<Product*> filter(std::vector<Product*> ProductItems, Specification<Product> & Spec) override
    {
        std::vector<Product*> result;
        for(auto& item : ProductItems)
        {
            if(Spec.is_statisfied(item))
            {
                result.push_back(item);
            }  
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product> {

    Color color;

    ColorSpecification(Color color): color{color} {}

    bool is_statisfied(Product* item)
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product> {

    Size size;

    SizeSpecification(Size size): size{size} {}

    bool is_statisfied(Product* item)
    {
        return item->size == size;
    }
};

// struct SizeAndColorSpecification : Specification<Product> {

//     Size size;
//     Color color;
//     SizeAndColorSpecification(Size size, Color color): size{size}, color{color} {}

//     bool is_statisfied(Product* item)
//     {
//         return item->size == size && item->color == color;
//     }
// };
template <typename T>
struct AndSpecification : Specification<T>{
    Specification<T> &first;
    Specification<T> &second;
    AndSpecification(Specification<T> &first, Specification<T> &second) : first{first}, second{second} {}
    bool is_statisfied(T* item) override
    {
        return first.is_statisfied(item) && second.is_statisfied(item);
    }
};
int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product*> items{&apple, &tree, &house};

    BetterFilter pf;
    //ColorSpecification GreenSpec{Color::green};
    // auto result = pf.filter(items, GreenSpec);

    // for(auto ele : result)
    // {
    //     std::cout << ele-> name  << " has green color " << std::endl;
    // }
    //SizeSpecification LargeSize{Size::large};
    // SizeAndColorSpecification LargeGreenSpec{Size::large, Color::green};
    // AndSpecification<Product> SizeAndColor {GreenSpec, LargeSize};

    ColorSpecification GreenSpec(Color::green);
    SizeSpecification LargeSize(Size::large);
    auto spec = GreenSpec && std::move(LargeSize);
    auto result = pf.filter(items, spec);

    for(auto ele : result)
    {
        std::cout << ele->name << " has large size" << std::endl;
    }
}