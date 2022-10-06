#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

#include "Form.hpp"
class Form;

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	~Bureaucrat(void);
	Bureaucrat &operator= (const Bureaucrat &bureaucrat);

	std::string const	&getName(void) const;
	int					getGrade(void) const;

	void	setGrade(int grade);
	void	increaseGrade(void);
	void	decreaseGrade(void);

	void	signForm(Form &form);
	void	executeForm(const Form &form);

private:
	const std::string	_name;
	static const int	_HIGHEST = 1;
	static const int	_LOWEST = 150;
	int					_grade;

	class GradeTooHighException: public std::exception {
	public:
		const char	*what(void) const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char	*what(void) const throw();
	};
};

std::ostream &operator<< (std::ostream &os, const Bureaucrat &bureaucrat);

#endif
