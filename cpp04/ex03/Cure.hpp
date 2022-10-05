/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:36 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:22:37 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {
public:
	Cure(void);
	Cure(const Cure &cure);
	~Cure(void);
	Cure &operator= (const Cure &cure);

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif
