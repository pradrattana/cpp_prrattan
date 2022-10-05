/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:18:02 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:18:04 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
public:
	Brain(void);
	Brain(const Brain &brain);
	~Brain(void);
	Brain &operator= (const Brain &brain);

	std::string	*getIdeas(void) const;
	void		setIdeas(const std::string &idea);

private:
	static const int	_MAX = 100;
	std::string			*ideas;
};

#endif
