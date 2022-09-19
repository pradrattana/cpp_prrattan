/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:55:07 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:55:10 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	std::cout << ">> Heap Zombie" << std::endl;
	Zombie	*heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << std::endl << ">> Stack Zombie" << std::endl;
	Zombie	stackZombie("Stack Zombie");
	stackZombie.announce();

	std::cout << std::endl << ">> Random Chump Zombie" << std::endl;
	randomChump("Random Chump Zombie");
	std::cout << std::endl;

	return (0);
}
