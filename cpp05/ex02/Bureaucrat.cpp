/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:34:30 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:34:31 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name("no-name"), _grade(Bureaucrat::_LOWEST) {
		std::cout << "Default constructor called by <Bureaucrat "
			<< this->getName() << ">" << std::endl;
	}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name) {
		std::cout << "Parameterized constructor called by <Bureaucrat "
			<< this->getName() << ">" << std::endl;
		this->setGrade(grade);
	}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):
	_name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {
		std::cout << "Copy constructor called by <Bureaucrat "
			<< this->getName() << ">" << std::endl;
		//*this = bureaucrat;
	}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Destructor called by <Bureaucrat "
		<< this->getName() << ">" << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &bureaucrat) {
	std::cout << "Copy assignment operator called by <Bureaucrat "
		<< bureaucrat.getName() << ">" << std::endl;
	//this->_name = bureaucrat.getName();
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	try {
		if (grade < Bureaucrat::_HIGHEST) {
			this->_grade = Bureaucrat::_HIGHEST;
			throw Bureaucrat::GradeTooHighException();
		} else if (grade > Bureaucrat::_LOWEST) {
			this->_grade = Bureaucrat::_LOWEST;
			throw Bureaucrat::GradeTooLowException();
		}
		this->_grade = grade;
	} catch (std::exception &e) {
		std::cout << "what(): " << e.what() << std::endl;
	}
}

void	Bureaucrat::increaseGrade(void) {
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decreaseGrade(void) {
	this->setGrade(this->getGrade() + 1);
}

void	Bureaucrat::signForm(Form &form) {
	std::cout << this->getName() << " ";
	try {
		form.beSigned(*this);
		std::cout << "signed " << form.getName();
	} catch (char const *msg) {
		std::cout << "couldn't sign " << form.getName()
			<< " because " << msg;
	} catch (std::exception &e) {
		std::cout << "couldn't sign " << form.getName()
			<< " because " << e.what();
	}
	std::cout << std::endl;
}

void	Bureaucrat::executeForm(const Form &form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " " << "executed " << form.getName();
	} catch (char const *msg) {
		std::cout << this->getName() << " " << "couldn't execute " << form.getName()
			<< " because " << msg;
	} catch (std::exception &e) {
		std::cout << this->getName() << " " << "couldn't execute " << form.getName()
			<< " because " << e.what();
	}
	std::cout << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat::Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat::Grade is too low.");
}

std::ostream &operator<< (std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (os);
}
