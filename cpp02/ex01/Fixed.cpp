#include "Fixed.hpp"

Fixed::Fixed(void):
	fixedPoint(0) {
		std::cout << "Default constructor called" << std::endl;
	}

Fixed::Fixed(const int i):
	fixedPoint(i << fractionalBits) {
		std::cout << "Int constructor called" << std::endl;
	}

Fixed::Fixed(const float f):
	fixedPoint(roundf(f * (1 << fractionalBits))) {
		std::cout << "Float constructor called" << std::endl;
	}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator= (const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
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

std::ostream &operator<< (std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}
