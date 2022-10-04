#include "Cat.hpp"

Cat::Cat(void):
	Animal("Cat") {
		std::cout << "Default constructor called by <Cat>" << std::endl;
	}

Cat::Cat(const Cat &cat) {
	std::cout << "Copy constructor called by <Cat>" << std::endl;
	*this = cat;
}

Cat::~Cat(void) {
	std::cout << "Destructor called by <Cat>" << std::endl;
}

Cat &Cat::operator= (const Cat &cat) {
	std::cout << "Copy assignment operator called by <Cat>" << std::endl;
	Animal::operator= (cat);
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "* MEOW~ MEOW *" << std::endl;
}
