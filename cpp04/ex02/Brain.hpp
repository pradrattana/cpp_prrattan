#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
public:
	Brain(void);
	Brain(const Brain &brain);
	~Brain(void);
	Brain &operator= (const Brain &brain);

	std::string	*getIdeas(void) const;
	void		setIdeas(const std::string &idea);

private:
	std::string	*ideas;
};

#endif
