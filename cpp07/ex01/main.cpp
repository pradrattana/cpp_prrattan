#include <iostream>
#include "iter.hpp"

template <typename T>
void	print(const T &x) {
	std::cout << x << std::endl;
}

template <typename T>
void	addCharA(T &x) {
	x += 'A';
}

int	main(void) {
	const int	myConstInt[] = { 100, 90, 80, 70, 60, 50 };
	int			myInt[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	std::string	myString[] = {
		"apple",
		"banana",
		"cherry",
		"durian",
		"eggplant"
	};
	
	std::cout << "myConstInt - print" << std::endl;
	iter(myConstInt, 6, print);
	std::cout << std::endl;

	std::cout << "myInt - addCharA" << std::endl;
	iter(myInt, 10, addCharA);
	std::cout << "myInt - print" << std::endl;
	iter(myInt, 10, print);
	std::cout << std::endl;

	std::cout << "myString - print" << std::endl;
	iter(myString, 5, print);
	std::cout << "myString - addCharA" << std::endl;
	iter(myString, 5, addCharA);
	std::cout << "myString - print" << std::endl;
	iter(myString, 5, print);

	return (0);
}
