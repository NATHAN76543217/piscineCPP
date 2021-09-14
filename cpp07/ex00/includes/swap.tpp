#ifndef SWAP_TPP
# define SWAP_TPP

template <typename T>
void        swap(T & lhs, T & rhs)
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

#endif          //SWAP_TPP 