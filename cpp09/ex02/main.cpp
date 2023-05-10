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

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

int	main(int argc, char **argv) {
	if (argc > 1) {
		PmergeMe<std::vector<int> >	byVector;
		PmergeMe<std::deque<int> >	byDeque;

		if (!byVector.init(argc, argv)) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		byDeque.init(argc, argv);

		std::cout << "Before: " << byVector << std::endl;
		float	timeVect = byVector.getFuncProcessorTime(&PmergeMe<std::vector<int> >::mergeDevide, byVector);
		std::cout << "After:  " << byVector << std::endl;

		std::cout << "Time to process a range of "
			<< byVector.getNumber().size()
			<< " elements with std::vector : "
			<< std::fixed << std::setprecision(5) << timeVect
			<< " us" << std::endl;

		std::cout << "Time to process a range of "
			<< byDeque.getNumber().size()
			<< " elements with std::deque  : "
			<< byDeque.getFuncProcessorTime(&PmergeMe<std::deque<int> >::mergeDevide, byDeque)
			<< " us" << std::endl;
	}
	return (0);
}

//https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
