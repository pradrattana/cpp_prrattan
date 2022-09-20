/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:00:16 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/20 12:05:21 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	h;
	if (argc == 2) {
		h.complain(argv[1]);
		return (0);
	}
	std::cout << "Error: Expected 1 argument (comment_level)" << std::endl;
	return (1);
}
