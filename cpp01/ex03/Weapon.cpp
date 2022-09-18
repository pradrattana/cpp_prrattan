/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:58:08 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:58:10 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void):
	type("no-type") {}

Weapon::Weapon(std::string type):
	type(type) {}

Weapon::~Weapon(void) {}

std::string const&	Weapon::getType(void) const {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
