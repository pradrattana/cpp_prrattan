#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (0);
	Zombie	*z = new Zombie[N];
	for (int i = 0; i < N; i++) {
		z[i].setName(name);
		z[i].announce();
	}
	return (z);
}
