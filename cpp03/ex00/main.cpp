/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:59:45 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 17:59:56 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	noName;
	ClapTrap	alex("Alex");
	ClapTrap	bob("Bob");
	ClapTrap	bob2(bob);

	std::cout << std::endl;
	noName.printStatus();
	alex.printStatus();
	bob.printStatus();
	bob2.printStatus();

	std::cout << std::endl;
	alex.takeDamage(9);
	alex.attack("Cara");
	alex.takeDamage(9);
	alex.printStatus();
	alex.attack("Cara");

	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		bob.beRepaired(1);
	}
	bob.printStatus();
	bob.attack("Cara");

	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		(i % 2) ? bob2.beRepaired(1) : bob2.takeDamage(1);
	}
	bob2.printStatus();
	bob2.attack("Cara");

	std::cout << std::endl;
	return (0);
}
