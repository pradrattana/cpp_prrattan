#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

/*bool	is_strnum(std::string &s) {
	std::string::const_iterator	it = s.begin();
	while (it != s.end()) {
		if (!std::isdigit(*it++)) {
			return (false);
		}
	}
	return (!s.empty());
}*/

void	Contact::setAttribute(int id) {
	std::string	temp;

	this->_id = id + 1;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, this->_firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, this->_phone);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, this->_secret);
}

void	Contact::printAttribute(void) {
	std::cout << std::left << std::setw(16) << "Index: " << this->_id << std::endl;
	std::cout << std::left << std::setw(16) << "First Name: " << this->_firstName << std::endl;
	std::cout << std::left << std::setw(16) << "Last Name: " << this->_lastName << std::endl;
	std::cout << std::left << std::setw(16) << "Nickname: " << this->_nickname << std::endl;
	std::cout << std::left << std::setw(16) << "Phone Number: " << this->_phone << std::endl;
	std::cout << std::left << std::setw(16) << "Darkest Secret: " << this->_secret << std::endl;
}

void	Contact::printRow(void) {
	std::cout << "|" << std::right << std::setw(10) << this->_id;
	if (this->_firstName.length() > 10)
		std::cout << "|" << this->_firstName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::right << std::setw(10) << this->_firstName;
	if (this->_lastName.length() > 10)
		std::cout << "|" << this->_lastName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::right << std::setw(10) << this->_lastName;
	if (this->_nickname.length() > 10)
		std::cout << "|" << this->_nickname.substr(0, 9) << ".";
	else
		std::cout << "|" << std::right << std::setw(10) << this->_nickname;
	std::cout << "|" << std::endl;
}
