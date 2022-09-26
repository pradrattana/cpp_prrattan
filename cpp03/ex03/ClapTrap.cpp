/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:59:34 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 17:59:35 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name("no-name"), _hit(10), _energy(10), _damage(0) {
		std::cout << "Default constructor called by <ClapTrap "
			<< this->_name << ">" << std::endl;
	}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hit(10), _energy(10), _damage(0) {
		std::cout << "Parameterized constructor called by <ClapTrap "
			<< this->_name << ">" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "Copy constructor called by <ClapTrap "
		<< clapTrap._name << ">" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called by <ClapTrap "
		<< this->_name << ">" << std::endl;
}

ClapTrap &ClapTrap::operator= (const ClapTrap &clapTrap) {
	std::cout << "Copy assignment operator called by <ClapTrap "
			<< clapTrap._name << ">" << std::endl;
	this->_name = clapTrap._name;
	this->_hit = clapTrap._hit;
	this->_energy = clapTrap._energy;
	this->_damage = clapTrap._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		std::cout << " attacks " << target << ", causing " << this->_damage << " points of damage!";
	}
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	if (this->checkStatus()) {
		if (amount < this->_hit)
			this->_hit -= amount;
		else
			this->_hit = 0;
		std::cout << " has attacked, losing " << amount << " hit points!";
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		this->_hit += amount;
		std::cout << " repairs itself, causing " << amount << " hit points back.";
	}
	std::cout << std::endl;
}

bool	ClapTrap::checkStatus(void) const {
	if (this->_energy == 0 || this->_hit == 0) {
		std::cout << " can't do anything, it has no "
			<< (this->_hit == 0 ? "hit" : "energy")
			<< " points left.";
		return (false);
	}
	return (true);
}

void	ClapTrap::printStatus(void) const {
	std::cout << "\e[0;36m[" << this->_name
		<< ": hitPoints=" << this->_hit
		<< ", energyPoints=" << this->_energy
		<< ", attackDamage=" << this->_damage << "]\e[0m" << std::endl;
}
