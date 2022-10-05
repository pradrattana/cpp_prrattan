/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:17:57 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/05 09:17:58 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default constructor called by <Brain>" << std::endl;
	this->ideas = new std::string[Brain::_MAX];
}

Brain::Brain(const Brain &brain) {
	std::cout << "Copy constructor called by <Brain>" << std::endl;
	*this = brain;
}

Brain::~Brain(void) {
	std::cout << "Destructor called by <Brain>" << std::endl;
	delete[] this->ideas;
}

Brain &Brain::operator= (const Brain &brain) {
	std::cout << "Copy assignment operator called by <Brain>" << std::endl;
	for (int i = 0; i < Brain::_MAX; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string	*Brain::getIdeas(void) const {
	return (this->ideas);
}

void	Brain::setIdeas(const std::string &idea) {
	if (!idea.empty()) {
		for (int i = 0; i < Brain::_MAX; i++) {
			if (this->ideas[i].empty()) {
				this->ideas[i] = idea;
				return ;
			}
		}
	}
	std::cout << "Warning: Not set an idea because the idea "
		<< (idea.empty() ? "is empty" : "slot is full") << std::endl;
}
