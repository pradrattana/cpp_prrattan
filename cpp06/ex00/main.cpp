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

#include <iostream>
#include "Convert.hpp"
#include <limits>
#include <cstring> 
#include <cstddef>

int	main(int argc, char **argv) {
	if (argc == 2) {
		Convert convert(argv[1]);

		convert.printOutput("char");
		convert.printOutput("int");
		convert.printOutput("float");
		convert.printOutput("double");
	} else {
		double	varmax[] = {
			std::numeric_limits<char>::max() - 1,
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
		for (int i = 0; i < 4; i++) {
			std::ostringstream	stream;
			stream << std::fixed << varmax[i];
			std::string	num(stream.str());
			Convert	convert(num.c_str());
			convert.printOutput();
			std::cout << std::endl;
		}
		for (int i = 0; i < 4; i++) {
			std::ostringstream	stream;
			stream << std::fixed << varmin[i];
			std::string	num(stream.str());
			Convert	convert(num.c_str());
			convert.printOutput();
			if (i < 3)
				std::cout << std::endl;
		}
	}
	return (0);
}

//https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
