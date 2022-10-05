/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:22:01 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:22:02 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# include "ICharacter.hpp"

class AMateria {
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &mtr);
	virtual ~AMateria(void);
	AMateria &operator= (const AMateria &mtr);

	std::string	const	&getType(void) const;
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string	type;
};

#endif
