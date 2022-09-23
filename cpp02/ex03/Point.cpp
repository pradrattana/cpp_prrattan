#include "Point.hpp"

Point::Point(void):
	x(0), y(0) {}

Point::Point(const float x, const float y):
	x(x), y(y) {}

Point::Point(const Point &point):
	x(point.x), y(point.y) {}

Point &Point::operator= (const Point &point) {
	(void)point;
	return (*this);
}

Point::~Point(void) {}

bool Point::operator== (const Point &point) {
	return (this->getX() == point.getX() && this->getY() == point.getY());
}

bool Point::operator!= (const Point &point) {
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
