#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack(void) {};
	MutantStack(const MutantStack &mutantStack):
		std::stack<T>(mutantStack) {};
	~MutantStack(void) {};
	MutantStack &operator= (const MutantStack &mutantStack) {
		std::stack<T>::operator= (mutantStack);
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	
	iterator	begin(void) {
		return (this->c.begin());
		// c is a protected member object of stack's underlying container
	};
	iterator	end(void) {
		return (this->c.end());
	};
	
	const_iterator	begin(void) const {
		return (this->c.begin());
	};
	const_iterator	end(void) const {
		return (this->c.end());
	};
};

#endif

//https://stackoverflow.com/questions/4820843/how-to-typedef-the-iterator-of-a-nested-container
//https://en.cppreference.com/w/cpp/container/stack
//https://en.cppreference.com/w/cpp/container/deque/begin
