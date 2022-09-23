#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &fixed); 
	Fixed &operator= (const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	static const int	fractionalBits = 8;
	int					fixedPoint;
};

#endif
