//https://en.cppreference.com/w/cpp/language/using_declaration

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap(void);
	DiamondTrap &operator= (const DiamondTrap &diamondTrap);

	void	whoAmI(void);

	using ScavTrap::attack;

private:
	std::string	_name;
};

#endif
