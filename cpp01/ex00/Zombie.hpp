/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:54:35 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:54:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);

private:
	std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
