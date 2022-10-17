/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:32:43 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:32:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("Presidential Pardon", PresidentialPardonForm::_SIGN, PresidentialPardonForm::_EXEC) {
		std::cout << "Default constructor called by <PresidentialPardonForm>" << std::endl;
	}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	Form("Presidential Pardon", PresidentialPardonForm::_SIGN, PresidentialPardonForm::_EXEC), _target(target) {
		std::cout << "Parameterized constructor called by <PresidentialPardonForm>" << std::endl;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pp):
	Form(pp), _target(pp._target) {
		std::cout << "Copy constructor called by <PresidentialPardonForm>" << std::endl;
	}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "Destructor called by <PresidentialPardonForm>" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &pp) {
	std::cout << "Copy assignment operator called by <PresidentialPardonForm>" << std::endl;
	Form::operator= (pp);
	this->_target = pp._target;
	return (*this);
}

void	PresidentialPardonForm::derivedExecute(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
