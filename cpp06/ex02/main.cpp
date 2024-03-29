/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:46:50 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:46:51 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void) {
	A	a;
	B	b;
	C	c;

	Base	&baseA = a;
	std::cout << "Class: A" << std::endl;
	identify(&baseA);
	identify(baseA);
	std::cout << std::endl;

	Base	*baseB = &b;
	std::cout << "Class: B" << std::endl;
	identify(baseB);
	identify(*baseB);
	std::cout << std::endl;

	std::cout << "Class: C" << std::endl;
	identify(&c);
	identify(c);
	std::cout << std::endl;

	Base	*baseGen = generate();
	identify(baseGen);
	identify(*baseGen);
	delete baseGen;

	std::cout << std::endl;

	Base	&baseGen2 = *generate();
	identify(&baseGen2);
	identify(baseGen2);
	delete &baseGen2;

	return (0);
}
