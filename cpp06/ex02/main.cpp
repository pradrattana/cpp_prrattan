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

	Base	&baseC = c;
	std::cout << "Class: C" << std::endl;
	identify(&baseC);
	identify(baseC);
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
