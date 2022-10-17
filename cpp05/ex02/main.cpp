#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void) {
	Bureaucrat	anne("Anne", 70);
	Bureaucrat	bob("Bob", 40);
	Bureaucrat	cara("Cara", 5);

	std::cout << std::endl;

	Form	*form[] = {
		new ShrubberyCreationForm("Apple"),
		new RobotomyRequestForm("Banana"),
		new PresidentialPardonForm("Cherry")
	};

	std::cout << std::endl;

	Bureaucrat	*bureaucrat[] = { &anne, &bob, &cara };

	for (int i = 0; i < 3; i++) {
		if (i > 0)
			anne.signForm(*form[i]);
		anne.executeForm(*form[i]);
		std::cout << *form[i] << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		bureaucrat[i]->signForm(*form[i]);
		bureaucrat[i]->executeForm(*form[i]);
		std::cout << std::endl;
		//std::cout << *bureaucrat[i] << std::endl;
		//std::cout << *form[i] << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		delete form[i];
	}

	return (0);
}
