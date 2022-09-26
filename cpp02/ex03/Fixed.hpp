/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:45:13 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:45:14 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &fixed);
	Fixed &operator= (const Fixed &fixed);
	~Fixed(void);

	bool operator> (const Fixed &fixed) const;
	bool operator< (const Fixed &fixed) const;
	bool operator>= (const Fixed &fixed) const;
	bool operator<= (const Fixed &fixed) const;
	bool operator== (const Fixed &fixed) const;
	bool operator!= (const Fixed &fixed) const;
	Fixed operator+ (const Fixed &fixed) const;
	Fixed operator- (const Fixed &fixed) const;
	Fixed operator* (const Fixed &fixed) const;
	Fixed operator/ (const Fixed &fixed) const;
	Fixed &operator++ (void);
	Fixed operator++ (int);
	Fixed &operator-- (void);
	Fixed operator-- (int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

private:
	static const int	fractionalBits = 8;
	int					fixedPoint;
};

std::ostream &operator<< (std::ostream &os, const Fixed &fixed);

#endif
