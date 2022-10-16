#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void) {
	Bureaucrat	anne("Anne", 70);
	Bureaucrat	bob("Bob", 40);
	Bureaucrat	cara("Cara", 5);
	Intern		newbie;

	std::cout << std::endl;

	Form	*scForm = newbie.makeForm("shrubbery creation", "Apple");
	Form	*rrForm = newbie.makeForm("Robotomy Request", "Banana");
	Form	*ppForm = newbie.makeForm("presidential pardon form", "Cherry");
	
	std::cout << std::endl << ">> Intern tries to make invalid form" << std::endl;
	Form	*temp = newbie.makeForm("abcde", "Durian");
	temp = newbie.makeForm("SHRUERY", "Durian");

	std::cout << std::endl;

	Form		*form[] = { scForm, rrForm, ppForm };
	Bureaucrat	*bureaucrat[] = { &anne, &bob, &cara };
	
	for (int i = 1; i < 3; i++) {
		bureaucrat[0]->signForm(*form[i]);
		bureaucrat[0]->executeForm(*form[i]);
		std::cout << *form[i] << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		bureaucrat[i]->signForm(*form[i]);
		bureaucrat[i]->executeForm(*form[i]);
		std::cout << std::endl;
		//std::cout << *bureaucrat[i] << std::endl;
		//std::cout << *form[i] << std::endl;
	}

	delete scForm;
	delete rrForm;
	delete ppForm;

	return (0);
}
