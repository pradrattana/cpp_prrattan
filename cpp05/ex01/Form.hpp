/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:31:57 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:32:04 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
public:
	Form(void);
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &form);
	~Form(void);
	Form &operator= (const Form &form);

	std::string const	&getName(void) const;
	bool				getSignedStat(void) const;
	int const			&getToSignGrade(void) const;
	int const			&getToExecGrade(void) const;

	void		checkGrade(int grade);
	void		beSigned(const Bureaucrat &bureaucrat);

private:
	const std::string	_name;
	static const int	_HIGHEST = 1;
	static const int	_LOWEST = 150;
	bool				_isSigned;
	const int			_toSign;
	const int			_toExec;

	class GradeTooHighException: public std::exception {
	public:
		const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char	*what() const throw();
	};
};

std::ostream &operator<< (std::ostream &os, const Form &form);

#endif
