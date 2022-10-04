#include "Dog.hpp"

Dog::Dog(void):
	Animal("Dog") {
		std::cout << "Default constructor called by <Dog>" << std::endl;
	}

Dog::Dog(const Dog &dog) {
	std::cout << "Copy constructor called by <Dog>" << std::endl;
	*this = dog;
}

Dog::~Dog(void) {
	std::cout << "Destructor called by <Dog>" << std::endl;
}

Dog &Dog::operator= (const Dog &dog) {
	std::cout << "Copy assignment operator called by <Dog>" << std::endl;
	Animal::operator= (dog);
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "* WOFF WOFF! *" << std::endl;
}
