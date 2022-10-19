#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template <typename T>
void	iter(const T *address, std::size_t length, void (*func)(const T &)) {
	for (std::size_t i = 0; i < length; i++) {
		(*func)(address[i]);
	}
}

template <typename T>
void	iter(T *address, std::size_t length, void (*func)(T &)) {
	for (std::size_t i = 0; i < length; i++) {
		(*func)(address[i]);
	}
}

#endif
