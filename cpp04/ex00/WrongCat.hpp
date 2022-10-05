/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:14:47 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:14:48 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &wrong);
	~WrongCat(void);
	WrongCat &operator= (const WrongCat &wrong);

	void	makeSound(void) const;
};

#endif
