#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main(void) {
	int	myInt[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	int	myIntSize = sizeof(myInt) / sizeof(myInt[0]);

	{
	std::vector<int>	myIntVect(myInt, myInt + myIntSize);
	std::vector<int>::iterator	begin = myIntVect.begin(), it;

	std::cout << ">> Find 1 in myIntVect" << std::endl;
	it = easyfind(myIntVect, 1);
	std::cout << "Element found at index: "
		<< std::distance(begin, it) << std::endl << std::endl;
	try {
		std::cout << ">> Find 25 in myIntVect" << std::endl;
		it = easyfind(myIntVect, 25);
		std::cout << "Element found at index: "
			<< std::distance(begin, it) << std::endl;
	} catch (const char *e) {
		std::cout << e << std::endl;
	}
	}
	
	std::cout << std::endl << "-------------------------" << std::endl;

	{
	std::list<char>	myCharList(7, 'A');
	std::list<char>::iterator	begin = myCharList.begin(), it;

	std::cout << ">> Find 'A' in myCharList" << std::endl;
	it = easyfind(myCharList, 'A');
	std::cout << "Element found at index: "
		<< std::distance(begin, it) << std::endl << std::endl;
	try {
		std::cout << ">> Find '0' in myCharList" << std::endl;
		it = easyfind(myCharList, '0');
		std::cout << "Element found at index: "
			<< std::distance(begin, it) << std::endl;
	} catch (const char *e) {
		std::cout << e << std::endl;
	}
	}

	return (0);
}
