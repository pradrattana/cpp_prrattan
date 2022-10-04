#include "Cure.hpp"

Cure::Cure(void):
	AMateria("cure") {
		//std::cout << "Default constructor called by <Cure>" << std::endl;
	}

Cure::Cure(const Cure &cure) {
	//std::cout << "Copy constructor called by <Cure>" << std::endl;
	*this = cure;
}

Cure::~Cure(void) {
	//std::cout << "Destructor called by <Cure>" << std::endl;
}

Cure &Cure::operator= (const Cure &cure) {
	//std::cout << "Copy assignment operator called by <Cure>" << std::endl;
	AMateria::operator= (cure);
	return (*this);
}

AMateria	*Cure::clone(void) const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
