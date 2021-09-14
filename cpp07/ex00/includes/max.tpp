#ifndef MAX_TPP
# define MAX_TPP

template <typename T>
T const &   max(T const & lhs, const T & rhs)
{
    return (lhs > rhs ? lhs : rhs);
}

#endif          //MAX_TPP 