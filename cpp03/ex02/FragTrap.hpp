/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:01:23 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:24 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap(void);
	FragTrap &operator= (const FragTrap &fragTrap);

	void	highFivesGuys(void);
};

#endif
