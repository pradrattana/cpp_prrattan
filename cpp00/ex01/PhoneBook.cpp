#include "PhoneBook.hpp"
  
PhoneBook::PhoneBook(void) {
	this->_nbContact = 0;
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
	std::string	c;

	if (this->_nbContact >= _MAX) {
		std::cout << "Warning: The phonebook is full, "
			<< "this action will replace the oldest one by the new one" << std::endl;
		do {
			std::cout << "Replace anyway? [Y/n]: ";
			std::getline(std::cin, c);
			if (c.compare("n") == 0 || c.compare("N") == 0)
				return ;
		} while (!(c.compare("y") == 0 || c.compare("Y") == 0));
	}
	this->_contacts[this->_nbContact % _MAX].setAttribute(this->_nbContact % _MAX);
	this->_nbContact++;
}

void	PhoneBook::searchContact(void) {
	int	id = -1;
	int	lim = (this->_nbContact > _MAX) ? _MAX : this->_nbContact;

	if (this->_nbContact <= 0) {
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
	do {
		std::cout << "Enter index to display informations: ";
		std::cin >> id;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (id >= 1 && id <= lim)
			this->_contacts[id - 1].printAttribute();
		else
			std::cout << "Error: Invalid index" << std::endl;
	} while (id < 1 || id > lim);
}
