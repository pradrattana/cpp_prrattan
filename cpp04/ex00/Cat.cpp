/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:14:10 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:14:11 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
	Animal("Cat") {
		std::cout << "Default constructor called by <Cat>" << std::endl;
	}

Cat::Cat(const Cat &cat):
	Animal("Cat") {
		std::cout << "Copy constructor called by <Cat>" << std::endl;
		*this = cat;
	}

Cat::~Cat(void) {
	std::cout << "Destructor called by <Cat>" << std::endl;
}

Cat &Cat::operator= (const Cat &cat) {
	std::cout << "Copy assignment operator called by <Cat>" << std::endl;
	//Animal::operator= (cat);
	(void)cat;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "* MEOW~ MEOW *" << std::endl;
}
