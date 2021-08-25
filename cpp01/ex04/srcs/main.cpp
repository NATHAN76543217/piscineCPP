#include "Replace.hpp"

int     main(int ac, char **av)
{
    if (ac == 4)
    {
        Replace rp(av[1]);
        rp.replace(av[2], av[3]); 
    }
    else
        std::cout << av[0] << " filename s1 s2" << std::endl;
    return 0;
}