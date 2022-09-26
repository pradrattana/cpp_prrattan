#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	clap("Clap");
	ScavTrap	alex("Alex");
	ScavTrap	bob("Bob");
	ScavTrap	bob2(bob);

	std::cout << std::endl;
	clap.printStatus();
	alex.printStatus();
	bob.printStatus();
	bob2.printStatus();

	std::cout << std::endl << ">> attack" << std::endl;
	clap.attack("Cara");
	alex.attack("Cara");

	std::cout << std::endl << ">> guardGate" << std::endl;
	// clap.guardGate();
	alex.guardGate();
	alex.printStatus();

	std::cout << std::endl;
	for (int i = 0; i < 10; i++) {
		(i % 2) ? bob.beRepaired(10) : bob.takeDamage(10);
	}
	bob.printStatus();
	bob.guardGate();
	bob.attack("Cara");
	bob.printStatus();

	std::cout << std::endl;
	return (0);
}
