/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:16:20 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:16:21 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
	Animal("Cat"), brain(new Brain()) {
		std::cout << "Default constructor called by <Cat>" << std::endl;
	}

Cat::Cat(const Cat &cat):
	Animal("Cat") {
		std::cout << "Copy constructor called by <Cat>" << std::endl;
		*this = cat;
	}

Cat::~Cat(void) {
	std::cout << "Destructor called by <Cat>" << std::endl;
	delete this->brain;
}

Cat &Cat::operator= (const Cat &cat) {
	std::cout << "Copy assignment operator called by <Cat>" << std::endl;
	//Animal::operator= (cat);
	this->brain = new Brain();
	*this->brain = *cat.brain;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "* MEOW~ MEOW *" << std::endl;
}

void	Cat::setIdeas(const std::string &idea) {
	this->brain->setIdeas(idea);
}

void	Cat::printIdeas(void) const {
	std::string	*ideas(this->brain->getIdeas());

	for (int i = 0; !ideas[i].empty(); i++) {
		std::cout << "[" << i << "]\t" << ideas[i] << std::endl;
	}
}
