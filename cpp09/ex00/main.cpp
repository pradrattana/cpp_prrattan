/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:46:02 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:46:03 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 2) {
		BitcoinExchange	btc(argv[1]);
		(void)btc;
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}
	return (0);
}
