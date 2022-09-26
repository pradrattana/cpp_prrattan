/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:00:23 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:00:24 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	clap("Clap");
	ScavTrap	scav("Scav");
	FragTrap	alex("Alex");
	FragTrap	bob("Bob");
	FragTrap	bob2(bob);

	std::cout << std::endl;
	clap.printStatus();
	scav.printStatus();
	alex.printStatus();
	bob.printStatus();
	bob2.printStatus();

	std::cout << std::endl << ">> attack" << std::endl;
	clap.attack("Cara");
	scav.attack("Cara");
	alex.attack("Cara");

	std::cout << std::endl << ">> highFivesGuys" << std::endl;
	// clap.highFivesGuys();
	// scav.highFivesGuys();
	alex.highFivesGuys();
	alex.printStatus();

	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		(i % 2) ? bob.takeDamage(40) : bob.highFivesGuys();
	}
	bob.printStatus();
	for (int i = 0; i < 4; i++) {
		(i % 2) ? bob.takeDamage(20) : bob.beRepaired(10);
	}
	bob.printStatus();
	bob.attack("Cara");
	bob.printStatus();

	std::cout << std::endl;
	return (0);
}
