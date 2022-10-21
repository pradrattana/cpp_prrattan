/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:30:32 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/19 13:31:10 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstdlib>

template <typename T>
class Array {
public:
	Array(void): _array(NULL), _size(0) {}

	Array(unsigned int n): _array(NULL), _size(n) {
		if (this->_size > 0) {
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = '\0';
			}
		}
	}

	Array(const Array &array) {
		*this = array;
	}

	~Array(void) {
		delete[] this->_array;
	}

	Array &operator= (const Array &array) {
		this->_array = NULL;
		this->_size = array.size();
		if (this->_size > 0) {
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = array._array[i];
			}
		}
		return (*this);
	}

	T &operator[] (int index) const {
		if (index >= 0)
			if (static_cast<unsigned int>(index) < this->_size)
				return (this->_array[index]);
		throw std::exception();
		//throw std::out_of_range("Index is out of bounds");
	}

	unsigned int	size(void) const {
		return (this->_size);
	}

private:
	T				*_array;
	unsigned int	_size;
};

#endif
