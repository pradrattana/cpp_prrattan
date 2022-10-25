#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

int	main( void ) {
	{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top  " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "size " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	++it;
	--it;
	std::cout << "print begin to end: ";
	while (it != ite) {
		std::cout << *it++ << " "; // std::endl;
	}
	std::cout << std::endl;

	std::stack<int>	s(mstack);
	}

	std::cout << "--------------------" << std::endl;

	{
	MutantStack<char>	charStack, charStackCopy;

	std::cout << ">> charStack" << std::endl;
	std::cout << "push ";
	for (int i = 0; i < 10; i++) {
		charStack.push(i + 'A');
		std::cout << "'" << charStack.top() << "'" << (i != 9 ? ", " : "\n");
	}
	std::cout << "[ size=" << charStack.size() << " ]" << std::endl;

	std::cout << "pop  ";
	for (int i = 0; i < 3; i++) {
		std::cout << "'" << charStack.top() << "'" << (i != 2 ? ", " : "\n");
		charStack.pop();
	}
	std::cout << "[ size=" << charStack.size() << " ]" << std::endl;

	std::cout << "now charStack: ";
	for (MutantStack<char>::const_iterator itc = charStack.begin(); itc != charStack.end(); itc++) {
		//*itc = 'S';
		std::cout << *itc << (itc + 1 != charStack.end() ?  ", " : "\n");
	}

	std::cout << std::endl << ">> copy to charStackCopy" << std::endl;
	charStackCopy = charStack;
	MutantStack<char>::iterator  it = charStackCopy.begin();
	std::cout << "charStackCopy.begin()    : " << *it << std::endl;
	std::advance(it, 3);
	std::cout << "charStackCopy.begin() + 3: " << *it << std::endl;
	std::cout << "distance between it and end: " << std::distance(it, charStackCopy.end()) << std::endl;
	}

	std::cout << std::endl;

	{
	std::list<char>	charList, charListCopy;

	std::cout << ">> charList" << std::endl;
	std::cout << "push ";
	for (int i = 0; i < 10; i++) {
		charList.push_back(i + 'A');
		std::cout << "'" << charList.back() << "'" << (i != 9 ? ", " : "\n");
	}
	std::cout << "[ size=" << charList.size() << " ]" << std::endl;

	std::cout << "pop  ";
	for (int i = 0; i < 3; i++) {
		std::cout << "'" << charList.back() << "'" << (i != 2 ? ", " : "\n");
		charList.pop_back();
	}
	std::cout << "[ size=" << charList.size() << " ]" << std::endl;

	std::cout << "now charList: ";
	for (std::list<char>::const_iterator itc = charList.begin(); itc != charList.end(); ) {
		std::cout << *itc << (++itc != charList.end() ?  ", " : "\n");
	}

	std::cout << std::endl << ">> copy to charListCopy" << std::endl;
	charListCopy = charList;
	std::list<char>::iterator  it = charList.begin();
	std::cout << "charListCopy.begin()    : " << *it << std::endl;
	std::advance(it, 3);
	std::cout << "charListCopy.begin() + 3: " << *it << std::endl;
	std::cout << "distance between it and end: " << std::distance(it, charList.end()) << std::endl;
	}

	return (0);
}
