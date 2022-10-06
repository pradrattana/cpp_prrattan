#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Default constructor called by <Intern>" << std::endl;
}

Intern::Intern(const Intern &intern) {
	std::cout << "Copy constructor called by <Intern>" << std::endl;
	*this = intern;
}

Intern::~Intern(void) {
	std::cout << "Destructor called by <Intern>" << std::endl;
}

Intern &Intern::operator= (const Intern &intern) {
	std::cout << "Copy assignment operator called by <Intern>" << std::endl;
	(void)intern;
	return (*this);
}

Form	*Intern::makeShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makePresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

static void	strToLower(std::string &s) {
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
    	*it = std::tolower(*it);
}

Form	*Intern::makeForm(const std::string &nameC, const std::string &target) {
	Form	*(Intern::*func[])(const std::string &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string	form[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	std::string	name = nameC;
	strToLower(name);
	for (int i = 0; i < 3; i++) {
		if (name.compare(form[i]) == 0 || name.compare(form[i] + " form") == 0) {
			std::cout << "Intern creates " << form[i] << " form" << std::endl;
			return ((this->*func[i])(target));
		}
	}
	std::cout << "Error: Intern cannot create " << nameC << std::endl;
	return (0);
}
