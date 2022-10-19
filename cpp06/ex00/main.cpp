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

#include "Convert.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 2) {
		Convert convert(argv[1]);
		std::cout << convert;
	} else {
		double	varmax[] = {
			std::numeric_limits<char>::max(),
			std::numeric_limits<int>::max(),
			std::numeric_limits<float>::max(),
			std::numeric_limits<double>::max()
		};
		double	varmin[] = {
			std::numeric_limits<char>::min(),
			std::numeric_limits<int>::min(),
			-std::numeric_limits<float>::max(),
			-std::numeric_limits<double>::max()
		};
		for (int i = 0; i < 8; i++) {
			//std::cout << std::fixed << std::setprecision(1) << (i < 4 ? varmax[i] : varmin[i - 4]) << std::endl;
			std::ostringstream	stream;
			stream << std::fixed << (i < 4 ? varmax[i] : varmin[i - 4]);
			Convert	convert(stream.str());
			std::cout << convert;
			if (i != 7)
				std::cout << std::endl;
		}
	}
	return (0);
}

//https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
