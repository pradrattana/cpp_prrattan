/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:02:21 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:02:22 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "Default constructor called by <ScavTrap "
		<< this->_name << ">" << std::endl;
	this->_hit = ScavTrap::_HIT;
	this->_energy = ScavTrap::_ENERGY;
	this->_damage = ScavTrap::_DAMAGE;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name) {
		std::cout << "Parameterized constructor called by <ScavTrap "
			<< this->_name << ">" << std::endl;
		this->_hit = ScavTrap::_HIT;
		this->_energy = ScavTrap::_ENERGY;
		this->_damage = ScavTrap::_DAMAGE;
	}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	std::cout << "Copy constructor called by <ScavTrap "
		<< scavTrap._name << ">" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destructor called by <ScavTrap "
		<< this->_name << ">" << std::endl;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &scavTrap) {
	std::cout << "Copy assignment operator called by <ScavTrap "
			<< scavTrap._name << ">" << std::endl;
	this->_name = scavTrap._name;
	this->_hit = scavTrap._hit;
	this->_energy = scavTrap._energy;
	this->_damage = scavTrap._damage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		std::cout << " attacks " << target << ", causing " << this->_damage << " points of damage!";
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		std::cout << " is now in Gate keeper mode.";
	}
	std::cout << std::endl;
}
