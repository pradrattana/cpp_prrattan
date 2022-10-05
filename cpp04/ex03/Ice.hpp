/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:24 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:22:26 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {
public:
	Ice(void);
	Ice(const Ice &ice);
	~Ice(void);
	Ice &operator= (const Ice &ice);

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif
