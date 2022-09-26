#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	std::cout << "Default constructor called by <FragTrap "
		<< this->_name << ">" << std::endl;
	this->_hit = FragTrap::_HIT;
	this->_energy = FragTrap::_ENERGY;
	this->_damage = FragTrap::_DAMAGE;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name) {
		std::cout << "Parameterized constructor called by <FragTrap "
			<< this->_name << ">" << std::endl;
		this->_hit = FragTrap::_HIT;
		this->_energy = FragTrap::_ENERGY;
		this->_damage = FragTrap::_DAMAGE;
	}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "Copy constructor called by <FragTrap "
		<< fragTrap._name << ">" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructor called by <FragTrap "
		<< this->_name << ">" << std::endl;
}

FragTrap &FragTrap::operator= (const FragTrap &fragTrap) {
	std::cout << "Copy assignment operator called by <FragTrap "
			<< fragTrap._name << ">" << std::endl;
	this->_name = fragTrap._name;
	this->_hit = fragTrap._hit;
	this->_energy = fragTrap._energy;
	this->_damage = fragTrap._damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name;
	if (this->checkStatus()) {
		this->_energy--;
		std::cout << " requests a positive high fives.";
	}
	std::cout << std::endl;
}
