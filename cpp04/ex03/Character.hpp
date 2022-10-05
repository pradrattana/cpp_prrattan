/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:15 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:22:16 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter {
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &character);
	~Character(void);
	Character &operator= (const Character &character);

	std::string const	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);

private:
	static const int	_MAX = 4;
	static const int	_MAX_UE = 100;
	AMateria			*slot[_MAX];
	std::string			name;
	AMateria			*unequipSlot[_MAX_UE];
};

#endif
 
