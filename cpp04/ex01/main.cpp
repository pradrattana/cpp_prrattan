/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:18:32 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:18:33 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define MAX_ANIMAL 6

int main(void) {
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << std::endl << "--------------------" << std::endl << std::endl;

	Animal  *animal[MAX_ANIMAL];

	for (int i = 0; i < MAX_ANIMAL; i++) {
		if (i % 2) {
			animal[i] = new Dog();
		} else {
			animal[i] = new Cat();
		}
	}

	std::cout << std::endl;
	
	std::cout << animal[0]->getType() << ": ";
	animal[0]->makeSound();
	std::cout << animal[1]->getType() << ": ";
	animal[1]->makeSound();

	std::cout << std::endl;

	for (int i = 0; i < MAX_ANIMAL; i++) {
		delete animal[i];
	}

	std::cout << std::endl << "--------------------" << std::endl << std::endl;

	Dog myDog;
	myDog.setIdeas("I would like to eat meat tonight.");
	Dog myFriendDog = myDog; // copy constructor
	myDog.setIdeas("Today is party day!");

	std::cout << std::endl;
	
	std::cout << "My dog ideas:" << std::endl;
	myDog.printIdeas();

	std::cout << std::endl << "My friend dog ideas:" << std::endl;
	myFriendDog.printIdeas();

	std::cout << std::endl;

	return (0);
}
