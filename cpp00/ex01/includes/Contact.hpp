#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <iomanip>

class Contact{
public:
	bool		filled;

	Contact(void);
	~Contact(void);
	void	fill();
	void	askFirstName(void);
	void	askLastName(void);
	void    askNickName(void);
	void    askLogin(void);
	void    askPostalAddress(void);
	void    askEmail(void);
	void    askPhone(void);
	void    askBirthday(void);
	void    askMeal(void);
	void    askUnderwear(void);
	void    askSecret(void);
	void	printInfo(void) const;
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string getNickName(void) const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string login;
	std::string email;
	std::string birthday;
	std::string meal;
	std::string underware_color;
	std::string secret;
	std::string	postal;
	std::string	phone;

};
#endif // CONTACT_CLASS_H