/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:01 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:57:03 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie	*horde;

	std::cout << ">> Horde Zombie" << std::endl;
	horde = zombieHorde(5, "Horde Zombie");
	for (int i = 0; i < 5; i++) {
		std::cout << "  > announce index " << i << std::endl;
		horde[i].announce();
	}
	std::cout << "  > delete" << std::endl;
	delete []horde;

	std::cout << std::endl << ">> Alone Zombie" << std::endl;
	horde = zombieHorde(1, "Alone Zombie");
	std::cout << "  > announce index " << 0 << std::endl;
	horde[0].announce();
	std::cout << "  > delete" << std::endl;
	delete []horde;

	std::cout << std::endl << ">> Failed Zombie" << std::endl;
	horde = zombieHorde(-1, "Failed Zombie");

	return (0);
}
