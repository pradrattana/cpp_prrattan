/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:56:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:56:52 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (0);
	Zombie	*z = new Zombie[N];
	for (int i = 0; i < N; i++) {
		z[i].setName(name);
		z[i].announce();
	}
	return (z);
}
