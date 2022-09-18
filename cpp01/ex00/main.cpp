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
	Zombie	stack_zombie("Stack Zombie");
	Zombie	*heap_zombie = newZombie("Heap Zombie");

	randomChump("Random Chump Zombie");
	delete heap_zombie;
	return (0);
}
