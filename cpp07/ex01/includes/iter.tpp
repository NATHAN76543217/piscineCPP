#ifndef ITER_TPP
# define ITER_TPP

template <typename T, typename I>
void        iter(T *ptr, I const & len, void (*func)(T &))
{
    if (!ptr || !func)
        return ;
    for (I i = 0; i < len ; i++)
    {
        func(ptr[i]);
    }
}

#endif          //ITER_TPP 