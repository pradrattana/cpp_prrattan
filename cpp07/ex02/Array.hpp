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

template <class T>
class Array {
public:
	Array(void): _num(NULL), _size(0) {}

	Array(unsigned int n): _num(NULL), _size(n) {
		if (this->_size > 0) {
			this->_num = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_num[i] = 0;
			}
		}
	}

	Array(const Array &array) {
		*this = array;
	}

	~Array(void) {
		delete[] this->_num;
	}

	Array &operator= (const Array &array) {
		this->_num = NULL;
		this->_size = array._size;
		if (this->_size > 0) {
			this->_num = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_num[i] = array._num[i];
			}
		}
		return (*this);
	}

	T &operator[] (int index) const {
		if (static_cast<unsigned int>(index) >= this->_size) {
			throw std::exception();
			//throw std::out_of_range("Index is out of bounds");
		}
		return (this->_num[index]);
	}

	unsigned int	size(void) const {
		return (this->_size);
	}

private:
	T				*_num;
	unsigned int	_size;
};

#endif
