/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:19 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:20 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "Default constructor called by <FragTrap "
		<< this->_name << ">" << std::endl;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name) {
		std::cout << "Parameterized constructor called by <FragTrap "
			<< this->_name << ">" << std::endl;
		this->_hit = 100;
		this->_energy = 100;
		this->_damage = 30;
	}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "Copy constructor called by <FragTrap "
		<< fragTrap._name << ">" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructor called by <FragTrap "
		<< this->_name << ">" << std::endl;
}

FragTrap &FragTrap::operator= (const FragTrap &fragTrap) {
	std::cout << "Copy assignment operator called by <FragTrap "
			<< fragTrap._name << ">" << std::endl;
	ClapTrap::operator= (fragTrap);
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		std::cout << " requests a positive high fives.";
	}
	std::cout << std::endl;
}
