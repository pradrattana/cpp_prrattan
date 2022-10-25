#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <exception>

template <typename T>
typename T::iterator	easyfind(T &container, int needle) {
	typename T::iterator	it;

	it = find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw "Element not found";
	return (it);
}

#endif
