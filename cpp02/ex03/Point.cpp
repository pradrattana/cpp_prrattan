/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:44 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):
	x(0), y(0) {
		// std::cout << "Default constructor called by Point" << std::endl;
	}

Point::Point(const float x, const float y):
	x(x), y(y) {
		// std::cout << "Parameterized constructor called by Point" << std::endl;
	}

Point::Point(const Point &point):
	x(point.x), y(point.y) {
		// std::cout << "Copy constructor called by Point" << std::endl;
	}

Point &Point::operator= (const Point &point) {
	(void)point;
	// std::cout << "Copy assignment operator called by Point" << std::endl;
	return (*this);
}

Point::~Point(void) {
	// std::cout << "Destructor called by Point" << std::endl;
}

bool Point::operator== (const Point &point) const {
	return (this->getX() == point.getX() && this->getY() == point.getY());
}

bool Point::operator!= (const Point &point) const {
	return (!(this->getX() == point.getX() && this->getY() == point.getY()));
}

Fixed	Point::getX(void) const {
	return (x);
}

Fixed	Point::getY(void) const {
	return (y);
}

std::ostream &operator<< (std::ostream &os, const Point &point) {
	os << "(" << point.getX() << ", " << point.getY() << ")";
    return (os);
}
