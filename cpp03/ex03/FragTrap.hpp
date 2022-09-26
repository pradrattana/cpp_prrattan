#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap(void);
	FragTrap &operator= (const FragTrap &fragTrap);

	void	highFivesGuys(void);

protected:
	static const unsigned int	_HIT = 100;
	static const unsigned int	_ENERGY = 100;
	static const unsigned int	_DAMAGE = 30;
};

#endif
