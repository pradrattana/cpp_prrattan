/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:14:44 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:14:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):
	WrongAnimal("WrongCat") {
		std::cout << "Default constructor called by <WrongCat>" << std::endl;
	}

WrongCat::WrongCat(const WrongCat &wrong) {
	std::cout << "Copy constructor called by <WrongCat>" << std::endl;
	*this = wrong;
}

WrongCat::~WrongCat(void) {
	std::cout << "Destructor called by <WrongCat>" << std::endl;
}

WrongCat &WrongCat::operator= (const WrongCat &wrong) {
	std::cout << "Copy assignment operator called by <WrongCat>" << std::endl;
	WrongAnimal::operator= (wrong);
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "* MEOW~ MEOW *" << std::endl;
}
