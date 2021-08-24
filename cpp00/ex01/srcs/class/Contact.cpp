# include "Contact.hpp"

Contact::Contact(void) : filled(false)
{
    return;
}

Contact::~Contact()
{
    return ;
}

void    Contact::fill(void)
{
    this->askFirstName();
    this->askLastName();
    this->askNickName();
    this->askLogin();
    this->askPostalAddress();
    this->askEmail();
    this->askPhone();
    this->askBirthday();
    this->askMeal();
    this->askUnderwear();
    this->askSecret();
    this->filled = true;
}

void    Contact::askFirstName(void)
{
    std::cout << "Please enter your first name:" << std::endl;
    std::getline(std::cin, this->_firstName);
    return ;
}

void    Contact::askLastName(void)
{
    std::cout << "Please enter your last name:" << std::endl;
    std::getline(std::cin, this->_lastName);
    return ;
}

void    Contact::askNickName(void)
{
    std::cout << "Please enter your nick name:" << std::endl;
    std::getline(std::cin, this->_nickname);
    return ;
}

void    Contact::askLogin(void)
{
    std::cout << "Please enter your login:" << std::endl;
    std::getline(std::cin, this->_login);
    return ;
}

void    Contact::askPostalAddress(void)
{
    std::cout << "Please enter your postal address:" << std::endl;
    std::getline(std::cin, this->_postal);
    return ;
}

void    Contact::askEmail(void)
{
    std::cout << "Please enter your email:" << std::endl;
    std::getline(std::cin, this->_email);
    return ;
}

void    Contact::askPhone(void)
{
    std::cout << "Please enter your phone number:" << std::endl;
    std::getline(std::cin, this->_phone);
    return ;
}

void    Contact::askBirthday(void)
{
    std::cout << "Please enter your birthday:" << std::endl;
    std::getline(std::cin, this->_birthday);
    return ;
}

void    Contact::askMeal(void)
{
    std::cout << "Please enter your favorite meal:" << std::endl;
    std::getline(std::cin ,this->_meal);
    return ;
}

void    Contact::askUnderwear(void)
{
    std::cout << "Please enter your underwear color:" << std::endl;
    std::getline(std::cin, this->_underware_color);
    return ;
}

void    Contact::askSecret(void)
{
    std::cout << "Please enter your darkest secret:" << std::endl;
    std::getline(std::cin, this->_secret);
    return ;
}

void    Contact::printInfo(void) const
{
    std::cout << std::left <<
    	std::setw(17) << "First name: " << this->_firstName << std::endl <<
	    std::setw(17) << "Last name: " << this->_lastName << std::endl <<
	    std::setw(17) << "Nickname: " << this->_nickname << std::endl <<
	    std::setw(17) << "Login: " << this->_login << std::endl <<
    	std::setw(17) << "Postal code: " << this->_postal << std::endl <<
	    std::setw(17) << "Email: " << this->_email << std::endl <<
	    std::setw(17) << "Phone number: " << this->_phone << std::endl <<
	    std::setw(17) << "Birthday: " << this->_birthday << std::endl <<
	    std::setw(17) << "Favorite meal: " << this->_meal << std::endl <<
	    std::setw(17) << "Underwear color: " << this->_underware_color << std::endl <<
	    std::setw(17) << "Darkest Secret:" << this->_secret << std::endl <<
        std::endl;
    return ;
}

std::string Contact::getFirstName(void) const{
    return this->_firstName;
}

std::string Contact::getLastName(void) const{
    return this->_lastName;
}

std::string Contact::getNickName(void) const{
    return this->_nickname;
}