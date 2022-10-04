#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
public:
	Animal(void);
	Animal(const std::string &type);
	Animal(const Animal &animal);
	virtual ~Animal(void);
	Animal &operator= (const Animal &animal);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;

protected:
	std::string	type;
};

#endif
