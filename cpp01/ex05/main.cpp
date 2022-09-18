/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:59:29 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:59:30 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	h;

	std::cout << "Harl makes a 'DEBUG' level comment" << std::endl;
	h.complain("debug");

	std::cout << std::endl << "Harl makes an 'INFO' level comment" << std::endl;
	h.complain("Info");

	std::cout << std::endl << "Harl makes a 'WARNING' level comment" << std::endl;
	h.complain("WARNING");

	std::cout << std::endl << "Harl makes an 'ERROR' level comment" << std::endl;
	h.complain("eRRor");
}
