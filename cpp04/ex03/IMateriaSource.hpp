/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:21:49 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:21:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

# include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource(void) {};

	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
