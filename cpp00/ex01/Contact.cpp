#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

bool	isStrnum(std::string s) {
	std::string::iterator	it = s.begin();

	while (it != s.end())
		if (!std::isdigit(*it++))
			return (false);
	return (!s.empty());
}

void	getInput(std::string *var, std::string title) {
	while (1) {
		std::cout << "Enter " << title << ": ";
		std::getline(std::cin, *var);
		if (!var->empty())
			break ;
		std::cout << "Error: Saved contact can't have empty fields" << std::endl;
	}
}

void	Contact::setAttribute(int id) {
	this->_id = id + 1;
	getInput(&this->_firstName, "First Name");
	getInput(&this->_lastName, "Last Name");
	getInput(&this->_nickname, "Nickname");
	while (1) {
		getInput(&this->_phone, "Phone Number");
		if (isStrnum(this->_phone))
			break ;
		std::cout << "Error: Phone number must contain numbers only" << std::endl;
	}
	getInput(&this->_secret, "Darkest Secret");
}

void	Contact::printAttribute(void) {
	std::cout << std::left << std::setw(16) << "Index: " << this->_id << std::endl
		<< std::left << std::setw(16) << "First Name: " << this->_firstName << std::endl
		<< std::left << std::setw(16) << "Last Name: " << this->_lastName << std::endl
		<< std::left << std::setw(16) << "Nickname: " << this->_nickname << std::endl
		<< std::left << std::setw(16) << "Phone Number: " << this->_phone << std::endl
		<< std::left << std::setw(16) << "Darkest Secret: " << this->_secret << std::endl;
}

void	printCol(std::string var) {
	if (var.length() > 10)
		std::cout << "|" << var.substr(0, 9) << ".";
	else
		std::cout << "|" << std::right << std::setw(10) << var;
}

void	Contact::printRow(void) {
	std::cout << "|" << std::right << std::setw(10) << this->_id;
	printCol(this->_firstName);
	printCol(this->_lastName);
	printCol(this->_nickname);
	std::cout << "|" << std::endl;
}
