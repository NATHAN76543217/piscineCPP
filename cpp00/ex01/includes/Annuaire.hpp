#ifndef ANNUAIRE_CLASS_H
# define ANNUAIRE_CLASS_H

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class Annuaire{
public:
    

    Annuaire(void);
    ~Annuaire(void);

    void	    		close(void);
	void				open(void);
    bool        		isOpen(void) const;
	static bool        youWantTo(std::string str);
	static std::string truncate(std::string str, size_t len);
	static size_t countSpecial(std::string str);
	static size_t sizeOfPrintable(std::string str, size_t nb);

private:

	int const	_nbMax;
	int			_nbRegistered;
    bool    	_open;
    Contact		_contacts[8];
	std::string _input;

    int         _command(std::string cmd);
	int         _askIndex(void) const;
    void	    _addContact(void);
    void	    _search(void) const;
    void        _displayCommands(void) const;
    std::string _askInput(void) const;
};

#endif //ANNUAIRE_CLASS_H