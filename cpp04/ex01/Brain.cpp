#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default constructor called by <Brain>" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain &brain) {
	std::cout << "Copy constructor called by <Brain>" << std::endl;
	*this = brain;
}

Brain::~Brain(void) {
	std::cout << "Destructor called by <Brain>" << std::endl;
	delete[] this->ideas;
}

Brain &Brain::operator= (const Brain &brain) {
	std::cout << "Copy assignment operator called by <Brain>" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string	*Brain::getIdeas(void) const {
	return (this->ideas);
}

void	Brain::setIdeas(const std::string &idea) {
	if (!idea.empty()) {
		for (int i = 0; i < 100; i++) {
			if (this->ideas[i].empty()) {
				this->ideas[i] = idea;
				return ;
			}
		}
	}
	std::cout << "Warning: Not set an idea because the idea "
		<< (idea.empty() ? "is empty" : "slot is full") << std::endl;
}
