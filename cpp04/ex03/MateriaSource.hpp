/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:23:03 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:23:04 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &mtrSource);
	~MateriaSource(void);
	MateriaSource &operator= (const MateriaSource &mtrSource);

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);

private:
	static const int	_MAX = 4;
	AMateria			*slot[_MAX];
};

#endif
