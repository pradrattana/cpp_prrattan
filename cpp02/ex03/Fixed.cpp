/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:35 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:37 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://stackoverflow.com/a/3403056
//https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e
//https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170

#include "Fixed.hpp"

Fixed::Fixed(void):
	fixedPoint(0) {
		// std::cout << "Default constructor called" << std::endl;
	}

Fixed::Fixed(const int i):
	fixedPoint(i << fractionalBits) {
		// std::cout << "Int constructor called" << std::endl;
	}

Fixed::Fixed(const float f):
	fixedPoint(roundf(f * (1 << fractionalBits))) {
		// std::cout << "Float constructor called" << std::endl;
	}

Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator= (const Fixed &fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator> (const Fixed &fixed) {
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator< (const Fixed &fixed) {
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>= (const Fixed &fixed) {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<= (const Fixed &fixed) {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator== (const Fixed &fixed) {
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!= (const Fixed &fixed) {
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+ (const Fixed &fixed) {
	Fixed	newFixed;
	newFixed.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (newFixed);
}

Fixed Fixed::operator- (const Fixed &fixed) {
	Fixed	newFixed;
	newFixed.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (newFixed);
}

Fixed Fixed::operator* (const Fixed &fixed) {
	Fixed	newFixed;
	newFixed.setRawBits(this->getRawBits() * fixed.getRawBits() >> fractionalBits);
	return (newFixed);
}

Fixed Fixed::operator/ (const Fixed &fixed) {
	Fixed	newFixed;
	newFixed.setRawBits((this->getRawBits() << fractionalBits) / fixed.getRawBits());
	return (newFixed);
}

Fixed &Fixed::operator++ (void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++ (int) {
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed &Fixed::operator-- (void) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator-- (int) {
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

void	Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

float	Fixed::toFloat(void) const {
	return (this->getRawBits() / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->getRawBits() >> fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

std::ostream &operator<< (std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}
