#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum Color
{
    red,
    green,
    orange
};

enum Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

template <typename T>
struct Specification
{
    virtual bool is_satisfied(T *item) const = 0;
};

template <typename T>
struct Filter
{
    // // 1. Although this tries to make the filter as generic as possible by parameterizing
    // // attribute, the need to provide the value makes this difficult
    // // One will have to write if conditions to find what the operator is in the first place

    // vector<Product> filter(const vector<Product> vec, string attribute, Color color)

    // // 2. The below filter is fine but is too narrow. If you want to filter by size later
    // // or by a combination of attributes, you will have to duplicate the code and make small
    // // changes to it
    // vector<Product *> by_color(vector<Product *> products, Color col)
    // {
    //     vector<Product *> result;

    //     for (auto product : products)
    //         if (product->color == col)
    //             result.push_back(product);

    //     return result;
    // }

    // virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
    vector<T *> filter(vector<T *> items, Specification<T> &spec)
    {
        vector<Product *> result;

        for (auto i : items)
            if (spec.is_satisfied(i))
                result.push_back(i);

        return result;
    }
};

struct ProductColorSpecification : Specification<Product>
{
    Color color;

    ProductColorSpecification(Color c) : color(c) {}

    bool is_satisfied(Product *item) const override
    {
        return item->color == color;
    }
};

struct ProductSizeSpecification : Specification<Product>
{
    Size size;

    ProductSizeSpecification(Size sz) : size(sz) {}

    bool is_satisfied(Product *item) const override
    {
        return item->size == size;
    }
};

struct ColorAndSizeSpecification : Specification<Product>
{
    Color color;
    Size size;

    ColorAndSizeSpecification(Color c, Size s) : color{c}, size{s} {};

    bool is_satisfied(Product *item) const override
    {
        return item->color == color && item->size == size;
    }
};

int main()
{
    Product apple{"apple", green, medium};
    Product peach{"peach", red, small};
    Product mango{"mango", green, large};
    Product banana{"banana", green, large};

    vector<Product *> products{&apple, &peach, &mango, &banana};

    Filter<Product> filter;

    // Filter by color
    cout << "Filter by color...."
         << endl;
    ProductColorSpecification green_spec{Color::green};

    vector<Product *> green_items = filter.filter(products, green_spec);

    for (auto i : green_items)
        cout << i->name << " is green." << endl;

    // Filter by size
    cout << "\nFilter by size...."
         << endl;
    ProductSizeSpecification large_spec{Size::large};

    vector<Product *> large_items = filter.filter(products, large_spec);

    for (auto i : large_items)
        cout << i->name << " is large." << endl;

    // Filter by color and size
    cout << "\nFilter by color and size...."
         << endl;
    ColorAndSizeSpecification green_and_large_spec{Color::green, Size::large};

    vector<Product *> green_and_large_items = filter.filter(products, green_and_large_spec);

    for (auto i : green_and_large_items)
        cout << i->name << " is green and large." << endl;

    // // Belongs to 2.
    // vector<Product *> green_things = filter.by_color(products, green);

    // for (auto product : green_things)
    //     cout << product->name << " is green." << endl;

    // Belongs to 3.

    return 0;
}