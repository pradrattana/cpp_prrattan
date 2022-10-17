#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	static bool	first = true;
	if (first) {
		srand(time(0));
		first = false;
	}

	std::cout << "Generate type: ";
	switch (std::rand() % 3) {
		case 0:
			std::cout << "A" << std::endl;
			return (new A());
		case 1:
			std::cout << "B" << std::endl;
			return (new B());
		case 2:
			std::cout << "C" << std::endl;
			return (new C());
		default:
			break ;
	}
	return (0);
}

void	identify(Base *p) {
	std::cout << "< *p as parameter > " << "This is type: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Base";
	std::cout << std::endl;
}

void	identify(Base &p) {
	std::cout << "< &p as parameter > " << "This is type: ";
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch(const std::exception &e) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch(const std::exception &e) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch(const std::exception &e) {}
	std::cout << "Base" << std::endl;
}

//https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
