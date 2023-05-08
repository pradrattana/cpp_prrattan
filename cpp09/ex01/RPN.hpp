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
# include <cstdio>
# include <cmath>
# include <stack>
# include <limits>

class RPN {
public:
	RPN(void);
	RPN(const std::string &inp);
	RPN(const RPN &inp);
	~RPN(void);
	RPN &operator= (const RPN &inp);

	int		intepret(const std::string &data);
	void	calculate(char sign);
	void	clear(void);

private:
	std::stack<int>	_number;
};

#endif
