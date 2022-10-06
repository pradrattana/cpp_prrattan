#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("Robotomy Request", RobotomyRequestForm::_SIGN, RobotomyRequestForm::_EXEC) {
		std::cout << "Default constructor called by <RobotomyRequestForm>" << std::endl;
	}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	Form("Robotomy Request", RobotomyRequestForm::_SIGN, RobotomyRequestForm::_EXEC), _target(target) {
		std::cout << "Parameterized constructor called by <RobotomyRequestForm>" << std::endl;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rr):
	Form(rr), _target(rr._target) {
		std::cout << "Copy constructor called by <RobotomyRequestForm>" << std::endl;
	}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "Destructor called by <RobotomyRequestForm>" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &rr) {
	std::cout << "Copy assignment operator called by <RobotomyRequestForm>" << std::endl;
	Form::operator= (rr);
	this->_target = rr._target;
	return (*this);
}

void	RobotomyRequestForm::derivedExecute(void) const {
	std::cout << "* DRILLING NOISE *" << std::endl;
	static bool	first = true;

	if (first) {
		srand(time(0));
		first = false;
	}
	if (std::rand() % 2) {
		std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
	} else {
		std::cout << this->_target << " failed." << std::endl;
	}
}
