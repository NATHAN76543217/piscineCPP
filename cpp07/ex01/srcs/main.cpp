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
    
    std::cout << "initial: " << std::endl;
    ::iter(array, 4, print<int>);

    std::cout << std::endl << std::endl << "by two:" << std::endl;
    ::iter(array, 4, byTwo<int>);
    ::iter(array, 4, print<int>);

    std::cout << std::endl << std::endl << "by two on three elements:" << std::endl;
    ::iter(array, 3, byTwo<int>);
    ::iter(array, 4, print<int>);

    std::string array_s[4] = {"un", "deux", "trois", "quatre"};

    std::cout << std::endl << std::endl << "initial: " << std::endl;
    ::iter(array_s, 4, print<std::string>);

    std::cout << std::endl << std::endl << "to upper: " << std::endl;
    ::iter(array_s, 4, strUpper);
    ::iter(array_s, 4, print<std::string>);

    float array_f[4] = {0.1f, 1.8f, 2.5f, 3.4f};
    
    std::cout << std::endl << std::endl << "initial: " << std::endl;
    ::iter(array_f, 4, print<float>);

    std::cout << std::endl << std::endl << "by two on two elements: " << std::endl;
    ::iter(array_f, 2, byTwo<float>);
    ::iter(array_f, 4, print<float>);
    
    return 0;
}