#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &wrong);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator= (const WrongAnimal &wrong);

	void			makeSound(void) const;
	std::string		getType(void) const;

protected:
	std::string	type;
};

#endif
