#ifndef PRINT_TPP
# define PRINT_TPP

#include <iostream>

template <typename T>
void        print(T & val)
{
    std::cout << val << ", ";
}

#endif          //PRINT_TPP 