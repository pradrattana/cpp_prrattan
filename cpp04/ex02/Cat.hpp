/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:16:13 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:16:15 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
public:
	Cat(void);
	Cat(const Cat &cat);
	~Cat(void);
	Cat &operator= (const Cat &cat);

	void	makeSound(void) const;
	void	setIdeas(const std::string &idea);
	void	printIdeas(void) const;

private:
	Brain	*brain;
};

#endif
