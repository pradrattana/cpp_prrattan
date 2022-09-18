#include "Zombie.hpp"

int main() {
	Zombie	*horde;
	int		hordeNumber = 10;
	
	horde = zombieHorde(hordeNumber, "Horde");
	delete [] horde;
	horde = zombieHorde(0, "fail");
	return (0);
}
