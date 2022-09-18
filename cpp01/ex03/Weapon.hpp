/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:58:13 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:58:14 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	std::string const&	getType(void) const;
	void				setType(std::string type);

private:
	std::string	type;
};

#endif
