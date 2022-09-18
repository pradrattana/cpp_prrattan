#include "Zombie.hpp"

Zombie::Zombie(void) {
	setName("no-name");
	//this->name = "no-name";
}

Zombie::Zombie(std::string name) {
	setName(name);
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
