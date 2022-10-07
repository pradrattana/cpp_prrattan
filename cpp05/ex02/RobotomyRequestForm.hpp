#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form {
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &rr);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &rr);

	void	derivedExecute(void) const;

private:
	std::string			_target;
	static const int	_SIGN = 72;
	static const int	_EXEC = 45;
};

#endif