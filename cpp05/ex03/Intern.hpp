/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:35:35 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:35:37 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern(void);
	Intern(const Intern &intern);
	~Intern(void);
	Intern &operator= (const Intern &intern);

	Form	*makeForm(const std::string &name, const std::string &target);

private:
	Form	*makeShrubberyCreationForm(const std::string &target);
	Form	*makeRobotomyRequestForm(const std::string &target);
	Form	*makePresidentialPardonForm(const std::string &target);
};

#endif
