/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:00:23 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 15:00:25 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
		<< std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	strToLower(std::string *s) {
	for (std::string::iterator it=s->begin(); it != s->end(); it++)
    	*it = std::tolower(*it);
}

void	Harl::complain(std::string level) {
	int	i;
	std::string	cmd[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	strToLower(&level);
	for (i = 0; i < 4; i++) {
		if (level.compare(cmd[i]) == 0)
			break ;
	}
	switch (i) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
