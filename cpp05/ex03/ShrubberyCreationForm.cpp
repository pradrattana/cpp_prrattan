#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("Shrubbery Creation", ShrubberyCreationForm::_SIGN, ShrubberyCreationForm::_EXEC) {
		std::cout << "Default constructor called by <ShrubberyCreationForm>" << std::endl;
	}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form("Shrubbery Creation", ShrubberyCreationForm::_SIGN, ShrubberyCreationForm::_EXEC), _target(target) {
		std::cout << "Parameterized constructor called by <ShrubberyCreationForm>" << std::endl;
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shc):
	Form(shc), _target(shc._target) {
		std::cout << "Copy constructor called by <ShrubberyCreationForm>" << std::endl;
	}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Destructor called by <ShrubberyCreationForm>" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &shc) {
	std::cout << "Copy assignment operator called by <ShrubberyCreationForm>" << std::endl;
	Form::operator= (shc);
	this->_target = shc._target;
	return (*this);
}

void	ShrubberyCreationForm::derivedExecute(void) const {
	std::string		name(this->_target + "_shrubbery");
	std::ofstream	out;

	out.open(name.c_str());
	if (!out.is_open()) {
		std::cout << name.c_str() << ": " << std::strerror(errno) << std::endl;
		return ;
	}
	out << "    oxoxoo    ooxoo  " << std::endl
		<< "  ooxoxo oo  oxoxooo " << std::endl
		<< " oooo xxoxoo ooo ooox" << std::endl
		<< " oxo o oxoxo  xoxxoxo" << std::endl
		<< "  oxo xooxoooo o ooo " << std::endl
		<< "    ooo\\oo\\  /o/o    " << std::endl
		<< "        \\  \\/ /      " << std::endl
		<< "         |   /       " << std::endl
		<< "         |  |        " << std::endl
		<< "         | D|        " << std::endl
		<< "         |  |        " << std::endl
		<< "         |  |        " << std::endl
		<< "  ______/____\\____   " << std::endl;
	out.close();
	//std::cout<< "write an ascii tree in " << this->_target  << std::endl;
}
