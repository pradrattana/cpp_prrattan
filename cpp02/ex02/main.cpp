/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:18 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:19 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "--------------------" << std::endl;

	a = Fixed( 100 );
	Fixed	c( -4.2f );

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - c = " << a - c << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / c = " << a / c << std::endl;
	std::cout << "b >  b = " << (b > b ? "yes" : "no") << std::endl;
	std::cout << "b >= b = " << (b >= b ? "yes" : "no") << std::endl;
	std::cout << "b == c = " << (b == c ? "yes" : "no") << std::endl;
	std::cout << "b != c = " << (b != c ? "yes" : "no") << std::endl;

	return 0;
}
