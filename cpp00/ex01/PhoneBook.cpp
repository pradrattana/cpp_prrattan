#include "PhoneBook.hpp"
  
PhoneBook::PhoneBook(void) {
	this->_n_contact = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::showWelcome(void) {
	std::cout << "*********************************************" << std::endl;
	std::cout << "**         WELCOME TO THE PHONEBOOK        **" << std::endl;
	std::cout << "**                                         **" << std::endl;
	std::cout << "** Please enter one of these commands      **" << std::endl;
	std::cout << "**   ADD:    to save a new contact         **" << std::endl;
	std::cout << "**   SEARCH: to display a specific contact **" << std::endl;
	std::cout << "**   EXIT:   to exit the program           **" << std::endl;
	std::cout << "*********************************************" << std::endl;
}

int	PhoneBook::showMenu(void) {
	std::string	inp;

	std::cout << "ADD, SEARCH or EXIT: ";
	std::getline(std::cin, inp);
	if (inp.compare("ADD") == 0)
		return (1);
	else if (inp.compare("SEARCH") == 0)
		return (2);
	else if (inp.compare("EXIT") == 0)
		return (3);
	return (0);
}

void	PhoneBook::addContact(void) {
	char	c = 0;

	if (this->_n_contact >= _MAX) {
		std::cout << "Warning: The phonebook is full, ";
		std::cout << "this action will replace the oldest one by the new one" << std::endl;
		while (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N')) {
			std::cout << "Replace anyway? [Y/n]: ";
			std::cin >> c;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (c == 'n' || c == 'N')
				return ;
		}
	}
	this->_contacts[this->_n_contact % _MAX].setAttribute(this->_n_contact % _MAX);
	this->_n_contact++;
}

void	PhoneBook::searchContact(void) {
	int	id = -1;
	int	lim = (this->_n_contact > _MAX) ? _MAX : this->_n_contact;

	if (this->_n_contact <= 0) {
		std::cout << "Error: Nothing to search, please 'ADD' before 'SEARCH'" << std::endl;
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < lim; i++) {
		this->_contacts[i].printRow();
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	while (id < 1 || id > lim) {
		std::cout << "Enter index to display informations: ";
		std::cin >> id;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (id >= 1 && id <= lim)
			this->_contacts[id - 1].printAttribute();
		else
			std::cout << "Error: Invalid index" << std::endl;
	}
}
