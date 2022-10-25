#include "Span.hpp"
#include <iostream>

int main(void) {
	{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "---------------" << std::endl;

	{
	Span	src(15);
	for (int i = 0; i < 10; i++) {
		(i % 2) ? src.addNumber((i - 2) * 2) : src.addNumber((i + 3) * 3);
	}
	Span	cpy(src);
	for (int i = 0; i < 7; i++) {
		try {
			cpy.addNumber((i + 9) * i);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "src: " << src << std::endl
		<< ">> shortestSpan: " << src.shortestSpan() << std::endl
		<< ">> longestSpan : " << src.longestSpan() << std::endl;
	std::cout << std::endl << "cpy: " << cpy << std::endl
		<< ">> shortestSpan: " << cpy.shortestSpan() << std::endl
		<< ">> longestSpan : " << cpy.longestSpan() << std::endl;
	}

	std::cout << std::endl << "---------------" << std::endl;

	{
	std::cout << "big: " << std::endl;
	Span	*big = new Span(11000);
	try {
		std::cout << ">> shortestSpan: " << big->shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	big->addNumber(1);
	try {
		std::cout << ">> longestSpan : " << big->longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	big->addNumber(2, 10001);
	try {
		big->addNumber(-1000, 10);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl
		<< ">> shortestSpan: " << big->shortestSpan() << std::endl
		<< ">> longestSpan : " << big->longestSpan() << std::endl;
	delete big;
	}

	return (0);
}
