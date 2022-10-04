#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):
	type("no-type") {
		std::cout << "Default constructor called by <WrongAnimal "
			<< this->getType() << ">" << std::endl;
	}

WrongAnimal::WrongAnimal(const std::string &type):
	type(type) {
		std::cout << "Parameterized constructor called by <WrongAnimal "
			<< this->getType() << ">" << std::endl;
	}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong) {
	std::cout << "Copy constructor called by <WrongAnimal "
		<< wrong.getType() << ">" << std::endl;
	*this = wrong;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Destructor called by <WrongAnimal "
		<< this->getType() << ">" << std::endl;
}

WrongAnimal &WrongAnimal::operator= (const WrongAnimal &wrong) {
	std::cout << "Copy assignment operator called by <WrongAnimal "
		<< wrong.getType() << ">" << std::endl;
	this->type = wrong.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "( silence... )" << std::endl;
}
