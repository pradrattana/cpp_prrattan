/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:26 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:27 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

static void	printAnswer(Point a, Point b, Point c, Point p) {
	std::cout << ">>> point" << p
		<< " is" << (bsp(a, b, c, p) ? "" : " \033[0;31mnot\033[0m")
		<< " in triangle" << std::endl;
}

int main( void ) {
	Point	a1(0, 0), b1(9.5f, 4.75f), c1(-8, 14.25f);
	std::cout << "Triangle with vertices: "
		<< "a" << a1 << ", "
		<< "b" << b1 << ", "
		<< "c" << c1 << std::endl;
	printAnswer(a1, b1, c1, b1);
	printAnswer(a1, b1, c1, Point(4.2f, 4.2f));
	printAnswer(a1, b1, c1, Point(0, 5.05f));
	
	std::cout << std::endl;

	Point	a2(-7.7f, 0), b2(-9.3f, 10), c2(0, 10);
	std::cout << "Triangle with vertices: "
		<< "a" << a2 << ", "
		<< "b" << b2 << ", "
		<< "c" << c2 << std::endl;
	printAnswer(a2, b2, c2, Point(0, 0));
	printAnswer(a2, b2, c2, Point(-0.1f, 9.9f));
	printAnswer(a2, b2, c2, Point(-5.3f, 10));
	printAnswer(a2, b2, c2, Point(-5.3f, 9.99f));

	return (0);
}
