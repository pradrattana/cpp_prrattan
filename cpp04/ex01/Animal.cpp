#include "Animal.hpp"

Animal::Animal(void):
	type("no-type") {
		std::cout << "Default constructor called by <Animal "
			<< this->getType() << ">" << std::endl;
	}

Animal::Animal(const std::string &type):
	type(type) {
		std::cout << "Parameterized constructor called by <Animal "
			<< this->getType() << ">" << std::endl;
	}

Animal::Animal(const Animal &animal) {
	std::cout << "Copy constructor called by <Animal "
		<< animal.getType() << ">" << std::endl;
	*this = animal;
}

Animal::~Animal(void) {
	std::cout << "Destructor called by <Animal "
		<< this->getType() << ">" << std::endl;
}

Animal &Animal::operator= (const Animal &animal) {
	std::cout << "Copy assignment operator called by <Animal "
		<< animal.getType() << ">" << std::endl;
	this->type = animal.getType();
	return (*this);
}

std::string	Animal::getType(void) const {
	return (this->type);
}

void	Animal::makeSound(void) const {
	std::cout << "( silence... )" << std::endl;
}
