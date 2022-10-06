#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	Bureaucrat	anne("Anne", 61);
	Bureaucrat	bob("Bob", 50);
	Bureaucrat	cara("Cara", 20);

	Form	apple("Apple", 149, 75);  // ok
	Form	banana("Banana", 60, 30); // ok
	Form	cherry("Cherry", 40, 20); // ok

	std::cout << std::endl;

	Bureaucrat	*bureaucrat[] = { &anne, &bob, &cara };
	Form		*form[] = { &apple, &banana, &cherry };
	
	for (int i = 0; i < 2; i++) {
		bureaucrat[0]->signForm(*form[i]);
		std::cout << *form[i] << std::endl;
	}

	std::cout << "before increase>> " << anne << std::endl;
	anne.increaseGrade();
	std::cout << "after increase >> " << anne << std::endl << std::endl;
	anne.signForm(banana);
	std::cout << banana << std::endl;

	for (int i = 0; i < 3; i++) {
		bureaucrat[i]->signForm(*form[i]);
		std::cout << *form[i] << std::endl;
	}

	return (0);
}
