/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:29:41 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:29:51 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main( void ) {
    Bureaucrat anne("Anne", 149);   // ok
    Bureaucrat bob("Bob", 10);      // ok
    Bureaucrat cara("Cara", 160);   // too low
    Bureaucrat david("David", -10); // too high

    std::cout << std::endl;

    std::cout << anne << std::endl;
    std::cout << bob << std::endl;
    std::cout << cara << std::endl;
    std::cout << david << std::endl;

    std::cout << std::endl;

    anne.decreaseGrade();
    std::cout << anne << std::endl;
    anne.decreaseGrade();
    std::cout << anne << std::endl;

    std::cout << std::endl;

    david.increaseGrade();
    std::cout << david << std::endl;

    std::cout << std::endl;
    return (0);
}
