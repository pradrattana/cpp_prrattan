#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap(void);
	ScavTrap &operator= (const ScavTrap &scavTrap);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif
