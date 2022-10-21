/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:32:51 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/19 13:32:52 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int	main(void) {
	Array<char>		myChar(3);
	unsigned int	size = myChar.size();
	std::cout << "myChar - size=" << size << std::endl;

	std::cout << "myChar - assign" << std::endl;
	for (unsigned int i = 0; i < size + 1; i++) {
		try {
			myChar[i] = i + 'A';
			std::cout << "assign " << myChar[i] << " to " << "myChar[" << i << "]" << std::endl;
		} catch (const std::exception &e) {
			//std::cout << "Index is out of bounds, ";
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "myChar - print" << std::endl;
	for (int i = -2; i < static_cast<int>(size); i++) {
		try {
			std::cout << myChar[i] << (i + 1 == static_cast<int>(size) ? "\n" : ", ");
		} catch (const std::exception &e) {
			//std::cout << "Index is out of bounds, ";
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "--------------------" << std::endl << std::endl;

	Array<std::string>	*mySrc = new Array<std::string>(5);
	size = mySrc->size();
	std::cout << "mySrc - size=" << size << std::endl;

	std::cout << "mySrc - assign" << std::endl;
	(*mySrc)[size / 2] = "MIDDLE";
	std::cout << "assign " << (*mySrc)[size / 2] << " to " << "mySrc[" << size / 2 << "]" << std::endl;
	std::cout << std::endl;

	Array<std::string>	myCpy(*mySrc);
	std::cout << "myCpy - size=" << myCpy.size() << std::endl;

	std::cout << "myCpy - assign" << std::endl;
	myCpy[0] = "FIRST";
	std::cout << "assign " << myCpy[0] << " to " << "myCpy[0]" << std::endl;
	myCpy[size - 1] = "LAST";
	std::cout << "assign " << myCpy[size - 1] << " to " << "myCpy[" << size - 1 << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "mySrc - print" << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << (*mySrc)[i] << (i + 1 == size ? "\n" : ", ");
	}
	delete mySrc;
	std::cout << std::endl;

	std::cout << "myCpy - print" << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << myCpy[i] << (i + 1 == size ? "\n" : ", ");
	}

	return (0);
}

/*
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
*/
