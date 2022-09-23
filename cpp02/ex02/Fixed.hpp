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

	bool operator> (const Fixed &fixed);
	bool operator< (const Fixed &fixed);
	bool operator>= (const Fixed &fixed);
	bool operator<= (const Fixed &fixed);
	bool operator== (const Fixed &fixed);
	bool operator!= (const Fixed &fixed);
	Fixed operator+ (const Fixed &fixed);
	Fixed operator- (const Fixed &fixed);
	Fixed operator* (const Fixed &fixed);
	Fixed operator/ (const Fixed &fixed);
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
