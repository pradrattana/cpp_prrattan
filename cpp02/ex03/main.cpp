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

int main( void ) {
    Point   a1(0, 0), b1(9, 0), c1(1, 10);
    std::cout << "Triangle with vertices: "
        << "a" << a1 << ", " << "b" << b1 << ", " << "c" << c1 << std::endl;
    std::cout << "\t> point" << Point(1.1f, 1.1f) << " "
        << (bsp(a1, b1, c1, Point(1.1f, 1.1f)) ? "is" : "is not") << " in triangle" << std::endl;
    std::cout << "\t> point" << Point(0, 1.1f) << " "
        << (bsp(a1, b1, c1, Point(0, 1.1f)) ? "is" : "is not") << " in triangle" << std::endl;
    
    std::cout << std::endl;

    Point   a2(0, 0), b2(9, 0), c2(5, 0);
    std::cout << "Triangle with vertices: "
        << "a" << a2 << ", " << "b" << b2 << ", " << "c" << c2 << std::endl;
    std::cout << "\t> point" << Point(1.1f, 1.1f) << " "
        << (bsp(a2, b2, c2, Point(1.1f, 1.1f)) ? "is" : "is not") << " in triangle" << std::endl;

    return (0);
}
