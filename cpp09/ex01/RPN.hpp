/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include <stack>

class RPN {
public:
	RPN(void);
	RPN(const std::string &inp);
	RPN(const RPN &inp);
	~RPN(void);
	RPN &operator= (const RPN &inp);

	int		init(const std::string &inp);
	int		intepret(const std::string &data);
	double	calculate(char sign);
	const double	&getResult(void) const;

private:
	std::stack<double>	_number;
};

#endif
