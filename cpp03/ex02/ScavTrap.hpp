/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:00:59 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:00 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap(void);
	ScavTrap &operator= (const ScavTrap &scavTrap);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif
