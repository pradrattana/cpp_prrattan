#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap	clap("Clap");
	ScavTrap	scav("Scav");
	FragTrap	frag("Frag");
	DiamondTrap	alex("Alex");
	DiamondTrap	bob("Bob");

	std::cout << std::endl << ">> whoAmI" << std::endl;
	alex.whoAmI();
	bob.whoAmI();

	std::cout << std::endl;
	clap.printStatus();
	scav.printStatus();
	frag.printStatus();
	alex.printStatus();
	bob.printStatus();

	std::cout << std::endl << ">> attack" << std::endl;
	clap.attack("Cara");
	scav.attack("Cara");
	frag.attack("Cara");
	alex.attack("Cara");

	std::cout << std::endl << ">> guardGate" << std::endl;
	// clap.guardGate();
	scav.guardGate();
	// frag.guardGate();
	alex.guardGate();
	alex.printStatus();

	std::cout << std::endl << ">> highFivesGuys" << std::endl;
	// clap.highFivesGuys();
	// scav.highFivesGuys();
	frag.highFivesGuys();
	alex.highFivesGuys();
	alex.printStatus();

	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		(i % 2) ? bob.takeDamage(40) : bob.highFivesGuys();
	}
	bob.printStatus();
	for (int i = 0; i < 4; i++) {
		(i % 2) ? bob.takeDamage(20) : bob.beRepaired(10);
	}
	bob.printStatus();
	bob.attack("Cara");
	bob.printStatus();

	std::cout << std::endl;
	return (0);
}
