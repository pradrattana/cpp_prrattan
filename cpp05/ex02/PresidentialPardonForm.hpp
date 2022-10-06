#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form {
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &pp);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &pp);

	void	derivedExecute(void) const;

private:
	std::string			_target;
	static const int	_SIGN = 25;
	static const int	_EXEC = 5;
};

#endif
