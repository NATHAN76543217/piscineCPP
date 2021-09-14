#include <iostream>
#include <string>
#include "iter.tpp"
#include "byTwo.tpp"
#include "print.tpp"

void    strUpper(std::string & str)
{
    for (size_t i = 0; i < str.length(); i++)
        str.at(i) = toupper(str.at(i));
}

int main( void )
{
    int array[4] = {0, 1, 2, 3};
    ::iter(array, 4, print<int>);
    ::iter(array, 4, byTwo<int>);
    std::cout << std::endl;
    ::iter(array, 4, print<int>);
    ::iter(array, 2, byTwo<int>);
    std::cout << std::endl;
    ::iter(array, 4, print<int>);

    std::string array_s[4] = {"un", "deux", "trois", "quatre"};
    ::iter(array_s, 4, strUpper);
    std::cout << std::endl;
    ::iter(array_s, 4, print<std::string>);
    
    float array_f[4] = {0.0f, 1.0f, 2.0f, 3.0f};
    std::cout << std::endl;
    ::iter(array_f, 4, print<float>);
    ::iter(array_f, 3, byTwo<float>);
    std::cout << std::endl;
    ::iter(array_f, 4, print<float>);
    return 0;
}