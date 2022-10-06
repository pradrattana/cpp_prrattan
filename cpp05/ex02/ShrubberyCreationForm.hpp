#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include <cstring>
# include <cerrno>

# include "Bureaucrat.hpp"
# include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public Form {
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shc);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &shc);

	void	derivedExecute(void) const;

private:
	std::string			_target;
	static const int	_SIGN = 145;
	static const int	_EXEC = 137;
};

#endif
