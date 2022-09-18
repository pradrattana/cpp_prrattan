/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:40 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:57:42 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void) const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
