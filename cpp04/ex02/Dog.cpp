#include "Dog.hpp"

Dog::Dog(void):
	Animal("Dog"), brain(new Brain()) {
		std::cout << "Default constructor called by <Dog>" << std::endl;
	}

Dog::Dog(const Dog &dog) {
	std::cout << "Copy constructor called by <Dog>" << std::endl;
	*this = dog;
}

Dog::~Dog(void) {
	std::cout << "Destructor called by <Dog>" << std::endl;
	delete this->brain;
}

Dog &Dog::operator= (const Dog &dog) {
	std::cout << "Copy assignment operator called by <Dog>" << std::endl;
	Animal::operator= (dog);
	this->brain = new Brain();
	*this->brain = *dog.brain;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "* WOFF WOFF! *" << std::endl;
}

void	Dog::setIdeas(const std::string &idea) {
	this->brain->setIdeas(idea);
}

void	Dog::printIdeas(void) const {
	std::string	*ideas(this->brain->getIdeas());

	for (int i = 0; !ideas[i].empty(); i++) {
		std::cout << "[" << i << "]\t" << ideas[i] << std::endl;
	}
}
