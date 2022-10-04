#include "Ice.hpp"

Ice::Ice(void):
	AMateria("ice") {
		//std::cout << "Default constructor called by <Ice>" << std::endl;
	}

Ice::Ice(const Ice &ice) {
	//std::cout << "Copy constructor called by <Ice>" << std::endl;
	*this = ice;
}

Ice::~Ice(void) {
	//std::cout << "Destructor called by <Ice>" << std::endl;
}

Ice &Ice::operator= (const Ice &ice) {
	//std::cout << "Copy assignment operator called by <Ice>" << std::endl;
	AMateria::operator= (ice);
	return (*this);
}

AMateria	*Ice::clone(void) const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
