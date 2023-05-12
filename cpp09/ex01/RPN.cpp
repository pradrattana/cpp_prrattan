/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:44 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
	// std::cout << "Default constructor called by <RPN>" << std::endl;
}

RPN::RPN(const std::string &inp) {
	if (!this->init(inp))
		std::cout << "Error" << std::endl;
	else
		std::cout << this->getResult() << std::endl;
}

RPN::RPN(const RPN &inp) {
	// std::cout << "Copy constructor called by <RPN>" << std::endl;
	*this = inp;
}

RPN::~RPN(void) {
	// std::cout << "Destructor called by <RPN>" << std::endl;
}

RPN &RPN::operator= (const RPN &src) {
	// std::cout << "Copy assignment operator called by <RPN>" << std::endl;
	this->_number = src._number;
	return (*this);
}

int	RPN::init(const std::string &inp) {
	std::istringstream	iss(inp);
	std::string			data;

	while (std::getline(iss, data, ' ')) {
		if (!data.empty()) {
			switch (int res = intepret(data)) {
				case '+':
				case '-':
				case '*':
				case '/':
					if (!calculate(res))
						return 0;
					break ;

				case 10:
					return 0;

				default:
					this->_number.push(res);
					break ;
			}
		}
	}
	return this->_number.size() == 1;
}

int	RPN::intepret(const std::string &data) {
	std::istringstream	iss(data);
	int 				res;

	if (std::string("+-*/").find(data) != std::string::npos
			&& data.length() == 1)
		return *data.c_str();

	iss >> res;
	if (res < 10 && iss.eof())
		return res;
	return 10;
}

double	RPN::calculate(char sign) {
	if (this->_number.size() < 2)
		return 0;

	double	b = this->_number.top();
	this->_number.pop();
	double	a = this->_number.top();
	this->_number.pop();

	switch (sign) {
		case '+':
			this->_number.push(a + b);
			break ;

		case '-':
			this->_number.push(a - b);
			break ;

		case '*':
			this->_number.push(a * b);
			break ;

		case '/':
			this->_number.push(a / b);
			break ;
	}
	return 1;
}

const double	&RPN::getResult(void) const {
	return this->_number.top();
}
