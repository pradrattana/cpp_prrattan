/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:56 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:58 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	virtual ~ScavTrap(void);
	ScavTrap &operator= (const ScavTrap &scavTrap);

	void	attack(const std::string &target);
	void	guardGate(void);

protected:
	static const unsigned int	_HIT = 100;
	static const unsigned int	_ENERGY = 50;
	static const unsigned int	_DAMAGE = 20;
};

#endif
