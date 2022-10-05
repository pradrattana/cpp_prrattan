/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:59 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:23:00 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	//std::cout << "Default constructor called by <MateriaSource>" << std::endl;
	for (int i = 0; i < MateriaSource::_MAX; i++) {
		this->slot[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource &mtrSource) {
	//std::cout << "Copy constructor called by <MateriaSource>" << std::endl;
	for (int i = 0; i < MateriaSource::_MAX; i++) {
		this->slot[i] = 0;
	}
	*this = mtrSource;
}

MateriaSource::~MateriaSource(void) {
	//std::cout << "Destructor called by <MateriaSource>" << std::endl;
	for (int i = 0; i < MateriaSource::_MAX; i++) {
		delete this->slot[i];
	}
}

MateriaSource &MateriaSource::operator= (const MateriaSource &mtrSource) {
	//std::cout << "Copy assignment operator called by <MateriaSource>" << std::endl;
	for (int i = 0; i < MateriaSource::_MAX; i++) {
		delete this->slot[i];
		this->slot[i] = (mtrSource.slot[i]) ? mtrSource.slot[i]->clone() : 0;
	}
	return (*this);
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MateriaSource::_MAX; i++) {
		if (!this->slot[i])
			continue ;
		if (type.compare(this->slot[i]->getType()) == 0)
			return (this->slot[i]->clone());
	}
	return (0);
}

void	MateriaSource::learnMateria(AMateria *m) {
	if (m) {
		for (int i = 0; i < MateriaSource::_MAX; i++) {
			if (!this->slot[i]) {
				this->slot[i] = m;
				return ;
			}
		}
		delete m;
	}
}
