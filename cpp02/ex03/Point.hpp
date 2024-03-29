/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:49 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:54 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>

# include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &point);
	Point &operator= (const Point &point);
	~Point(void);

	bool operator== (const Point &point) const;
	bool operator!= (const Point &point) const;

	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	const Fixed	x;
	const Fixed	y;
};

std::ostream &operator<< (std::ostream &os, const Point &point);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
