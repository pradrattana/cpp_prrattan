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
		double	timeVect, timeDeque;

		if (!byVector.init(argc, argv)) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		byDeque.init(argc, argv);
		std::cout << "Before:  " << byVector << std::endl;

		timeVect = byVector.getFuncProcessingTime(
			&PmergeMe<std::vector<int> >::mergeInsertionSort, byVector
		);
		timeDeque = byDeque.getFuncProcessingTime(
			&PmergeMe<std::deque<int> >::mergeInsertionSort, byDeque
		);
		std::cout << "After:   " << byVector << std::endl;

		std::cout << "Time to process a range of "
			<< byVector.getSequence().size()
			<< " elements with std::vector : "
			<< std::fixed << std::setprecision(5) << timeVect
			<< " us" << std::endl;

		std::cout << "Time to process a range of "
			<< byDeque.getSequence().size()
			<< " elements with std::deque  : "
			<< timeDeque
			<< " us" << std::endl;
	}
	return (0);
}
