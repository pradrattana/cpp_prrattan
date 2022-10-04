#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &wrong);
	~WrongCat(void);
	WrongCat &operator= (const WrongCat &wrong);

	void	makeSound(void) const;
};

#endif
