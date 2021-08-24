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
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _login;
	std::string _email;
	std::string _birthday;
	std::string _meal;
	std::string _underware_color;
	std::string _secret;
	std::string	_postal;
	std::string	_phone;

};
#endif // CONTACT_CLASS_H