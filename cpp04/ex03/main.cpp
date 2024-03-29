/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:21:31 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:21:32 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main(void) {
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob); 
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "---------------------------" << std::endl << std::endl;

	std::cout << "++++++++ COPY TEST ++++++++" << std::endl;
	{
	std::cout << "> MateriaSource" << std::endl;

	MateriaSource	tmpSrc;
	tmpSrc.learnMateria(new Ice());
	MateriaSource	cpy(tmpSrc); // copy constructor
	tmpSrc.learnMateria(new Cure());

	std::cout << "src: ";
	tmp = tmpSrc.createMateria("cure");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << ", ";
	delete tmp;
	tmp = tmpSrc.createMateria("ice");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	delete tmp;
	std::cout << "cpy: ";
	tmp = cpy.createMateria("cure");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << ", ";
	delete tmp;
	tmp = cpy.createMateria("ice");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	delete tmp;
	}

	std::cout << std::endl;

	{
	std::cout << "> Character" << std::endl;

	MateriaSource	tmpSrc;
	tmpSrc.learnMateria(new Cure());
	tmpSrc.learnMateria(new Ice());

	Character		alex("Alex"), cara("Cara");
	alex.equip(tmpSrc.createMateria("ice"));
	Character		alex2("Alex2");
	alex2.equip(tmpSrc.createMateria("cure"));
	alex2.unequip(0);
	alex2 = alex; // copy assignment
	alex.equip(tmpSrc.createMateria("cure"));

	std::cout << "src: " << std::endl;
	alex.use(0, alex2);
	for (int i = 1; i < 4; i++)
		alex.use(i, cara);
	std::cout << "cpy: " << std::endl;
	for (int i = 0; i < 4; i++)
		alex2.use(i, cara);
	}

	std::cout << std::endl;

	std::cout << "+++++ CREATE MATERIA ++++++" << std::endl;
	{
	MateriaSource   tmpSrc;

	std::cout << "> before learn materia    : ";
	tmp = tmpSrc.createMateria("ice");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;

	std::cout << "> after learn materia     : ";
	tmpSrc.learnMateria(new Ice());
	tmp = tmpSrc.createMateria("ice");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	delete tmp;

	std::cout << "> create with invalid type: ";
	tmp = tmpSrc.createMateria("abcde");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "++++++ LEARN MATERIA ++++++" << std::endl;
	{
	MateriaSource   tmpSrc;

	std::cout << "> learn all the same type : ";
	for (int i = 0; i < 4; i++)
		tmpSrc.learnMateria(new Cure());
	tmp = tmpSrc.createMateria("cure");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	delete tmp;

	std::cout << "> learn after slot is full: ";
	tmpSrc.learnMateria(new Ice());
	tmp = tmpSrc.createMateria("ice");
	std::cout << "type=" << (tmp ? tmp->getType() : "NULL") << std::endl;
	}

	std::cout << std::endl;

	std::cout << "+++++ EQUIP & UNEQUIP +++++" << std::endl;
	{
	Character		alex("Alex"), cara("Cara");
	MateriaSource	tmpSrc;
	tmpSrc.learnMateria(new Cure());
	tmpSrc.learnMateria(new Ice());

	std::cout << "> equip all the same type : " << std::endl;
	for (int i = 0; i < 4; i++)
		alex.equip(tmpSrc.createMateria("cure"));
	for (int i = 0; i < 4; i++)
		alex.use(i, cara);

	std::cout << std::endl << "> equip after slot is full: " << std::endl;
	alex.equip(tmpSrc.createMateria("ice"));
	for (int i = 0; i < 5; i++)
		alex.use(i, cara);

	std::cout << std::endl << "> unequip to equip new one: " << std::endl;
	alex.unequip(2);
	alex.unequip(1);
	alex.unequip(100);
	alex.equip(tmpSrc.createMateria("ice")); // will fill equip slot[1]
	for (int i = 0; i < 4; i++)
		alex.use(i, cara);
	}

	return (0);
}
