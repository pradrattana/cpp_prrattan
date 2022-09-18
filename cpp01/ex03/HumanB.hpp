/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:57:49 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:57:51 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon &waepon);

private:
	std::string	name;
	Weapon		*weapon;
};

#endif
