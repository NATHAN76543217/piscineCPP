# include <string>
# include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *pstr = &str;
    std::string &rstr = str;

    std::cout << *pstr << std::endl;
    std::cout << rstr << std::endl;
    return 0;
}