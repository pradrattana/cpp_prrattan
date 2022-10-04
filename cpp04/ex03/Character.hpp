#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter {
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &character);
	~Character(void);
	Character &operator= (const Character &character);

	std::string const	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);

private:
	/*typedef struct unequipList {
		AMateria			*data;
		struct unequipList	*next;
	}	unequipList_t;

	void	unequipListAdd(unequipList_t **head, unequipList_t *node);
	void	unequipListClear(unequipList_t **head);*/

	static const int	_MAX = 4;
	AMateria			*slot[_MAX];
	std::string			name;
	AMateria			*unequipSlot[100];
	//unequipList_t		*uneqipHead;
};

#endif
 