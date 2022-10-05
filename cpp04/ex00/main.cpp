/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:15:03 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:15:05 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void) {
	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();

	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "--------------------" << std::endl << std::endl;

	const WrongAnimal	*wAni = new WrongCat();
	const WrongCat		*wCat = new WrongCat();

	std::cout << std::endl;

	std::cout << wAni->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	wAni->makeSound(); //will output WrongAnimal sound!
	wCat->makeSound(); //will output WrongCat sound!

	std::cout << std::endl;

	delete wAni;
	delete wCat;

	return (0);
}
