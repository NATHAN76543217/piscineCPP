#ifndef ANNUAIRE_CLASS_H
# define ANNUAIRE_CLASS_H

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "utils.hpp"

class Annuaire{
public:
    Contact contacts[8];
	int     nbRegistered;
	int     nbMax;
    
    Annuaire(void);
    ~Annuaire(void);
    void        displayCommands(void) const;
    void	    close(void);
    void	    addContact(void);
    void	    search(void) const;
    bool        isOpen(void) const;
    int         command(std::string cmd);
    std::string askInput(void) const;

private:
    bool    _open;

	int         askIndex(void) const;
};

#endif //ANNUAIRE_CLASS_H