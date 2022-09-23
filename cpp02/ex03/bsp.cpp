#include "Point.hpp"

bool	isTriangle(Point a, Point b, Point c) {
	if (a == b || a == c || b == c)
		return (false);
	if ((a.getY() - b.getY()) * (a.getX() - c.getX()) == (a.getY() - c.getY()) * (a.getX() - b.getX()))
		return (false);
	return (true);
}

Fixed	getTriangleArea(Point const a, Point const b, Point const c) {
	Fixed	ax_by(a.getX() * b.getY());
	Fixed	bx_cy(b.getX() * c.getY());
	Fixed	cx_ay(c.getX() * a.getY());

	Fixed	bx_ay(b.getX() * a.getY());
	Fixed	cx_by(c.getX() * b.getY());
	Fixed	ax_cy(a.getX() * c.getY());

	Fixed	area(Fixed(0.5f) * (((ax_by + bx_cy) + cx_ay) - ((bx_ay + cx_by) + ax_cy)));

	if (area >= Fixed(0))
		return (area);
	return (area * Fixed(-1));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (!isTriangle(a, b, c))
		return (false);

	Fixed	areaSum(getTriangleArea(a, b, c));
	Fixed	area1(getTriangleArea(point, a, b));
	Fixed	area2(getTriangleArea(point, a, c));
	Fixed	area3(getTriangleArea(point, b, c));

	if ((area1 == Fixed(0)) || (area2 == Fixed(0)) || (area3 == Fixed(0)))
		return (false);
	if ((area1 / areaSum > Fixed(1)) || (area2 / areaSum > Fixed(1)) || (area3 / areaSum > Fixed(1)))
		return (false);

	Fixed	ratio(((area1 + area2) + area3) / areaSum);
	return (ratio > Fixed(0.99f) && ratio < Fixed(1.01f));
}
