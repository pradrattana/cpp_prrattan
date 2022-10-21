/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <limits>

class Convert {
public:
	Convert(void);
	Convert(const std::string &convert);
	Convert(const Convert &convert);
	~Convert(void);
	Convert &operator= (const Convert &convert);

	const std::string	&getInputType(void) const;
	void	printCharOutput(void) const;
	void	printIntOutput(void) const;
	void	printFloatOutput(void) const;
	void	printDoubleOutput(void) const;

private:
	std::string	_type;
	double		_double;
	float		_float;
	int			_int;
	char		_char;
};

std::ostream &operator<< (std::ostream &os, const Convert &convert);

#endif
