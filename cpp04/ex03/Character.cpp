/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:11 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:22:12 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void):
	name("no-name") {
		//std::cout << "Default constructor called by <Character "
		//	<< this->getName() << ">" << std::endl;
		for (int i = 0; i < Character::_MAX; i++) {
			this->slot[i] = 0;
		}
		for (int i = 0; i < Character::_MAX_UE; i++) {
			this->unequipSlot[i] = 0;
		}
	}

Character::Character(const std::string &name):
	name(name) {
		//std::cout << "Parameterized constructor called by <Character "
		//	<< this->getName() << ">" << std::endl;
		for (int i = 0; i < Character::_MAX; i++) {
			this->slot[i] = 0;
		}
		for (int i = 0; i < Character::_MAX_UE; i++) {
			this->unequipSlot[i] = 0;
		}
	}

Character::Character(const Character &character) {
	//std::cout << "Copy constructor called by <Character "
	//	<< character.getName() << ">" << std::endl;
	for (int i = 0; i < Character::_MAX; i++) {
		this->slot[i] = 0;
	}
	for (int i = 0; i < Character::_MAX_UE; i++) {
		this->unequipSlot[i] = 0;
	}
	*this = character;
}

Character::~Character(void) {
	//std::cout << "Destructor called by <Character "
	//	<< this->getName() << ">" << std::endl;
	for (int i = 0; i < Character::_MAX; i++) {
		delete this->slot[i];
	}
	for (int i = 0; i < Character::_MAX_UE; i++) {
		delete this->unequipSlot[i];
	}
}

Character &Character::operator= (const Character &character) {
	//std::cout << "Copy assignment operator called by <Character "
	//	<< character.getName() << ">" << std::endl;
	this->name = character.getName();
	for (int i = 0; i < Character::_MAX; i++) {
		delete this->slot[i];
		this->slot[i] = (character.slot[i]) ? character.slot[i]->clone() : 0;
	}
	for (int i = 0; i < Character::_MAX_UE; i++) {
		delete this->unequipSlot[i];
		this->unequipSlot[i] = (character.unequipSlot[i]) ? character.unequipSlot[i]->clone() : 0;
	}
	return (*this);
}

std::string const	&Character::getName(void) const {
	return (this->name);
}

void	Character::equip(AMateria *m) {
	if (m) {
		for (int i = 0; i < Character::_MAX; i++) {
			if (!this->slot[i]) {
				this->slot[i] = m;
				return ;
			}
		}
		delete m;
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < Character::_MAX) {
		if (this->slot[idx]) {
			for (int i = 0; i < Character::_MAX_UE; i++) {
				if (!this->unequipSlot[i]) {
					this->unequipSlot[i] = this->slot[idx];
					break ;
				}
				//else if (i == Character::_MAX_UE - 1) {
				//	delete this->slot[idx];
				//}
			}
			this->slot[idx] = 0;
		}
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < Character::_MAX) {
		if (this->slot[idx])
			this->slot[idx]->use(target);
	}
}
