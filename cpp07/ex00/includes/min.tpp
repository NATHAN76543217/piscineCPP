#ifndef MIN_TPP
# define MIN_TPP

template <typename T>
T const &   min(T const & lhs, T const & rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

#endif          //MIN_TPP 