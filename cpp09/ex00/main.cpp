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
		BitcoinExchange	convert(argv[1]);
		(void)convert;
		// convert.splitLine("2011-01-03 | 3");
		// convert.intepretLine("2011-01-03 | 3");
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}
	return (0);
}

//https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
