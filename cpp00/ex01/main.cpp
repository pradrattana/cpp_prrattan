/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:01:58 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/16 10:01:59 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	p;
	int			mode;

	p.showWelcome();
	while (1) {
		std::cout << std::endl;
		mode = p.showMenu();
		if (mode == 1)
			p.addContact();
		else if (mode == 2) 
			p.searchContact();
		else if (mode == 3)
			break ;
		else
			std::cout << "Error: Invalid command" << std::endl;
	}
}
