/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:54 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:57:56 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	name(name), weapon(0) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const {
	std::cout << this->name;
	if (this->weapon)
		std::cout << " attacks with their " << this->weapon->getType();
	else
		std::cout << " has no weapon ";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
