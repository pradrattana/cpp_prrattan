/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:18:19 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:18:20 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
public:
	Dog(void);
	Dog(const Dog &Dog);
	~Dog(void);
	Dog &operator= (const Dog &Dog);

	void	makeSound(void) const;
	void	setIdeas(const std::string &idea);
	void	printIdeas(void) const;

private:
	Brain	*brain;
};

#endif
