#include "AMateria.hpp"

AMateria::AMateria(void):
	type("no-type") {
		//std::cout << "Default constructor called by <AMateria "
		//	<< this->getType() << ">" << std::endl;
	}

AMateria::AMateria(const std::string &type):
	type(type) {
		//std::cout << "Parameterized constructor called by <AMateria "
		//	<< this->getType() << ">" << std::endl;
	}

AMateria::AMateria(const AMateria &mtr) {
	//std::cout << "Copy constructor called by <AMateria "
	//	<< mtr.getType() << ">" << std::endl;
	*this = mtr;
}

AMateria::~AMateria(void) {
	//std::cout << "Destructor called by <AMateria "
	//	<< this->getType() << ">" << std::endl;
}

AMateria &AMateria::operator= (const AMateria &mtr) {
	//std::cout << "Copy assignment operator called by <AMateria "
	//	<< mtr.getType() << ">" << std::endl;
	this->type = mtr.getType();
	return (*this);
}

std::string	const	&AMateria::getType(void) const {
	return (this->type);
}

void	AMateria::use(ICharacter &target) {
	std::cout << "* uses a materia at " << target.getName() << " *" << std::endl;
	//(void)target;
	//std::cout << "Using a " << this->getType() << " Materia on " << target.getName() << std::endl;
}
