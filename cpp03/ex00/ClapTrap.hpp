/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:59:38 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 17:59:39 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap(void);
	ClapTrap &operator= (const ClapTrap &clapTrap);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	printStatus(void) const;

private:
	std::string		_name;
	unsigned int	_hit;
	unsigned int	_energy;
	unsigned int	_damage;

	bool	checkStatus(void) const;
};

#endif
