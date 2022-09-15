#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	showWelcome(void);
	int		showMenu(void);
	void	addContact(void);
	void	searchContact(void);

private:
	static const int	_MAX = 8;
	Contact				_contacts[_MAX];
	int					_nbContact;
};

#endif
