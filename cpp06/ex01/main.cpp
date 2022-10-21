/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:46:17 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:46:18 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int	main(void) {
	Data	before;
	before.str = "Hello World";
	before.num = 99;

	std::cout << "Data before serialize" << std::endl
		<< "> address: " << &before << std::endl
		<< "> str    : " << before.str << std::endl
		<< "> num    : " << before.num << std::endl;

	uintptr_t	ret = serialize(&before);
	Data		*after = deserialize(ret);

	std::cout << std::endl;
	std::cout << "Data after deserialize" << std::endl
		<< "> address: " << after << std::endl
		<< "> str    : " << after->str << std::endl
		<< "> num    : " << after->num << std::endl;

	return (0);
}
