/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:37:37 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/25 12:37:38 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void):
	_size(0) {
		//std::cout << "Default constructor called by <Span>" << std::endl;
	}

Span::Span(unsigned int n):
	_size(n) {
		//std::cout << "Parameterized constructor called by <Span>" << std::endl;
	}

Span::Span(const Span &span) {
	//std::cout << "Copy constructor called by <Span>" << std::endl;
	*this = span;
}

Span::~Span(void) {
	//std::cout << "Destructor called by <Span>" << std::endl;
}

Span &Span::operator= (const Span &span) {
	//std::cout << "Copy assignment operator called by <Span>" << std::endl;
	this->_size = span._size;
	this->_number = span._number;
	return (*this);
}

void	Span::addNumber(int n) {
	if (this->_number.size() + 1 > this->_size) {
		throw std::out_of_range("The slot is full.");
	}
	this->_number.push_back(n);
}

void	Span::addNumber(int start, int end) {
	for (int i = start; i < end; i++) {
		this->addNumber(i);
	}
}

void	Span::addNumber(int *arr, int size) {
	int	empty = this->_size - this->_number.size();

	if (size > 0) {
		if (size <= empty) {
			this->_number.insert(this->_number.end(), arr, arr + size);
		} else {
			if (empty > 0)
				this->_number.insert(this->_number.end(), arr, arr + empty);
			throw std::out_of_range("The slot is full.");
		}
	}
}

int	Span::shortestSpan(void) const {
	if (this->_number.size() <= 1)
		throw std::out_of_range("The span cannot be found.");

	std::vector<int>	vect1(this->_number);
	std::sort(vect1.begin(), vect1.end());

	std::vector<int>	vect2(vect1.size());
	std::rotate_copy(vect1.begin(), vect1.begin() + 1, vect1.end(), vect2.begin());

	std::vector<int>	diff;
	std::transform(vect1.begin(), vect1.end(), vect2.begin(),
		std::back_inserter(diff), std::minus<int>());

	int	(*absolute)(int) = &std::abs;
	std::transform(diff.begin(), diff.end(),
		diff.begin(), absolute);

	std::sort(diff.begin(), diff.end());
	return (diff.front());
}

int	Span::longestSpan(void) const {
	if (this->_number.size() <= 1)
		throw std::out_of_range("The span cannot be found.");

	std::vector<int>	vect(this->_number);
	std::sort(vect.begin(), vect.end());
	return (vect.back() - vect.front());
}

const std::vector<int>	&Span::getNumber(void) const {
    return (this->_number);
}

std::ostream &operator<< (std::ostream &os, const Span &span) {
	std::vector<int>	vect(span.getNumber());
	//os << "Span: ";
	for (std::vector<int>::const_iterator itc = vect.begin(); itc != vect.end(); itc++) {
		os << *itc << (itc + 1 != vect.end() ?  ", " : "");
	}
	return (os);
}
