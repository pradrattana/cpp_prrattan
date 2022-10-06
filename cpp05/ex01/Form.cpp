#include "Form.hpp"

Form::Form(void):
	_name("no-name"), _isSigned(false), _toSign(Form::_LOWEST), _toExec(Form::_LOWEST) {
		std::cout << "Default constructor called by <Form "
			<< this->getName() << ">" << std::endl;
	}

Form::Form(const std::string &name, int toSign, int toExec):
	_name(name), _isSigned(false), _toSign(toSign), _toExec(toExec) {
		std::cout << "Parameterized constructor called by <Form "
			<< this->getName() << ">" << std::endl;
		checkGrade(this->getToSignGrade());
		checkGrade(this->getToExecGrade());
	}

Form::Form(const Form &form):
	_name(form.getName()), _isSigned(form.getSignedStat()),
		_toSign(form.getToSignGrade()), _toExec(form.getToExecGrade()) {
		std::cout << "Copy constructor called by <Form "
			<< this->getName() << ">" << std::endl;
		checkGrade(this->getToSignGrade());
		checkGrade(this->getToExecGrade());
	}

Form::~Form(void) {
	std::cout << "Destructor called by <Form "
		<< this->getName() << ">" << std::endl;
}

Form &Form::operator= (const Form &form) {
	std::cout << "Copy assignment operator called by <Form "
		<< form.getName() << ">" << std::endl;
	//this->_name = form.getName();
	this->_isSigned = form.getSignedStat();
	//this->_toSign = form.getToSignGrade();
	//this->_toExec = form.getToExecGrade();
	return (*this);
}

std::string const	&Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSignedStat(void) const {
	return (this->_isSigned);
}

int const	&Form::getToSignGrade(void) const {
	return (this->_toSign);
}

int const	&Form::getToExecGrade(void) const {
	return (this->_toExec);
}

void	Form::checkGrade(int grade) {
	try {
		if (grade < Form::_HIGHEST) {
			throw Form::GradeTooHighException();
		} else if (grade > Form::_LOWEST) {
			throw Form::GradeTooLowException();
		}
	} catch (std::exception &e) {
		std::cout << "what(): " << e.what() << std::endl;
	}
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getToSignGrade()) {
		throw Form::GradeTooLowException();
	} else if (this->getSignedStat()) {
		throw "the form is already signed.";
	}
	this->_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("Form::Grade is too high.");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Form::Grade is too low.");
}

std::ostream &operator<< (std::ostream &os, const Form &form) {
	os << "Form name                : " << form.getName() << std::endl;
	os << "Current form status      : " << (form.getSignedStat() ? "" : "not ") << "signed" << std::endl;
	os << "Grade required to sign   : " << form.getToSignGrade() << std::endl;
	os << "Grade required to execute: " << form.getToExecGrade() << std::endl;
    return (os);
}
