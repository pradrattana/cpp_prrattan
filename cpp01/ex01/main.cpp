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
	int		hordeNumber = 10;
	
	horde = zombieHorde(hordeNumber, "Horde");
	delete [] horde;
	horde = zombieHorde(0, "fail");
	return (0);
}
