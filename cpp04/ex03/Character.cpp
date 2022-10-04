#include "Character.hpp"

Character::Character(void):
	name("no-name") {
		//std::cout << "Default constructor called by <Character "
		//	<< this->getName() << ">" << std::endl;
		for (int i = 0; i < Character::_MAX; i++) {
			this->slot[i] = 0;
		}
		for (int i = 0; i < 100; i++) {
			this->unequipSlot[i] = 0;
		}
		//this->uneqipHead = 0;
	}

Character::Character(const std::string &name):
	name(name) {
		//std::cout << "Parameterized constructor called by <Character "
		//	<< this->getName() << ">" << std::endl;
		for (int i = 0; i < Character::_MAX; i++) {
			this->slot[i] = 0;
		}
		for (int i = 0; i < 100; i++) {
			this->unequipSlot[i] = 0;
		}
		//this->uneqipHead = 0;
	}

Character::Character(const Character &character) {
	//std::cout << "Copy constructor called by <Character "
	//	<< character.getName() << ">" << std::endl;
	*this = character;
}

Character::~Character(void) {
	//std::cout << "Destructor called by <Character "
	//	<< this->getName() << ">" << std::endl;
	for (int i = 0; i < Character::_MAX; i++) {
		delete this->slot[i];
	}
	//unequipListClear(&this->uneqipHead);
	for (int i = 0; i < 100; i++) {
		delete this->unequipSlot[i];
	}
}

Character &Character::operator= (const Character &character) {
	//std::cout << "Copy assignment operator called by <Character "
	//	<< character.getName() << ">" << std::endl;
	this->name = character.getName();
	for (int i = 0; i < Character::_MAX; i++) {
		this->slot[i] = (character.slot[i]) ? character.slot[i]->clone() : 0;
	}
	/*this->uneqipHead = 0;
	//if (character.uneqipHead) {
		unequipList_t	*cur = character.uneqipHead;
		while (cur) {

			cur = cur->next;
		}
	//}*/
	for (int i = 0; i < 100; i++) {
		this->unequipSlot[i] = (character.unequipSlot[i]) ? character.unequipSlot[i]->clone() : 0;
	}
	return (*this);
}

std::string const	&Character::getName(void) const {
	return (this->name);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < Character::_MAX; i++) {
		if (!this->slot[i]) {
			this->slot[i] = m;
			return ;
		}
	}
	delete m;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < Character::_MAX) {
		if (this->slot[idx]) {
			for (int i = 0; i < 100; i++) {
				if (!this->unequipSlot[i]) {
					this->unequipSlot[i] = this->slot[idx];
					break ;
				}
			}
			/*unequipList_t	*node = new unequipList_t();
			node->data = this->slot[idx];
			unequipListAdd(&this->uneqipHead, node);*/
			this->slot[idx] = 0;
		}
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < Character::_MAX) {
		if (this->slot[idx])
			this->slot[idx]->use(target);
	}
}

/*void	Character::unequipListAdd(unequipList_t **head, unequipList_t *node) {
	if (!head)
		return ;
	node->next = *head;
	*head = node;
}

void	Character::unequipListClear(unequipList_t **head) {
	if (!(head && *head))
		return ;
	unequipListClear(&(*head)->next);
	delete (*head)->data;
	delete *head;
}*/
