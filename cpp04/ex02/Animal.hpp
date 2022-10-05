/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:20:52 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:20:53 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &animal);
	virtual ~Animal(void);
	Animal &operator= (const Animal &animal);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:
	std::string	type;
};

#endif
