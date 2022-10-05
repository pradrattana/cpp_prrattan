/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:14:13 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:14:15 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

# include "Animal.hpp"

class Cat: public Animal {
public:
	Cat(void);
	Cat(const Cat &cat);
	~Cat(void);
	Cat &operator= (const Cat &cat);

	void	makeSound(void) const;
};

#endif
