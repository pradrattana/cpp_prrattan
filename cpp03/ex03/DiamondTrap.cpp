/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:31 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:33 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap("no-name_clap_name"), _name("no-name") {
		std::cout << "Default constructor called by <DiamondTrap "
			<< this->_name << ">" << std::endl;
		this->_hit = FragTrap::_HIT;
		this->_energy = ScavTrap::_ENERGY;
		this->_damage = FragTrap::_DAMAGE;
	}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), _name(name) {
		std::cout << "Parameterized constructor called by <DiamondTrap "
			<< this->_name << ">" << std::endl;
		this->_hit = FragTrap::_HIT;
		this->_energy = ScavTrap::_ENERGY;
		this->_damage = FragTrap::_DAMAGE;
	}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	std::cout << "Copy constructor called by <DiamondTrap "
		<< diamondTrap._name << ">" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor called by <DiamondTrap "
		<< this->_name << ">" << std::endl;
}

DiamondTrap &DiamondTrap::operator= (const DiamondTrap &diamondTrap) {
	std::cout << "Copy assignment operator called by <DiamondTrap "
			<< diamondTrap._name << ">" << std::endl;
	ClapTrap::operator= (diamondTrap);
	this->_name = diamondTrap._name;
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is " << this->_name
		<< ". My ClapTrap name is " << this->ClapTrap::_name << "." << std::endl;
}
