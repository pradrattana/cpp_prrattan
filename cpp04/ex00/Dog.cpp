/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:14:23 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:14:23 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
	Animal("Dog") {
		std::cout << "Default constructor called by <Dog>" << std::endl;
	}

Dog::Dog(const Dog &dog):
	Animal("Dog") {
		std::cout << "Copy constructor called by <Dog>" << std::endl;
		*this = dog;
	}

Dog::~Dog(void) {
	std::cout << "Destructor called by <Dog>" << std::endl;
}

Dog &Dog::operator= (const Dog &dog) {
	std::cout << "Copy assignment operator called by <Dog>" << std::endl;
	//Animal::operator= (dog);
	(void)dog;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "* WOFF WOFF! *" << std::endl;
}
