/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:44:51 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/26 09:44:53 by prrattan         ###   ########.fr       */
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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	static const int	fractionalBits = 8;
	int					fixedPoint;
};

std::ostream &operator<< (std::ostream &os, const Fixed &fixed);

#endif
