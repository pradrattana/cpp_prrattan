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
	//std::cout << "Default constructor called by <RPN>" << std::endl;
}

int	RPN::intepret(const std::string &data) {
	std::istringstream	iss(data);
	int 				res;

	if (std::string("+-*/").find(data) != std::string::npos)
		return *data.c_str();

	iss >> res;
	if (res < 10 && iss.eof())
		return res;
	return 10;
}

void	RPN::calculate(char sign) {
	if (_number.size() < 2) {
		clear();
		std::cout << "Error" << std::endl;
		exit(1);
	}

	int	b = _number.top();
	_number.pop();
	int	a = _number.top();
	_number.pop();

	switch (sign) {
		case '+':
			_number.push(a + b);
			break ;

		case '-':
			_number.push(a - b);
			break ;

		case '*':
			_number.push(a * b);
			break ;

		case '/':
			_number.push(a / b);
			break ;
	}
}

void	RPN::clear(void) {
	while (_number.size() > 0)
		_number.pop();
}

RPN::RPN(const std::string &inp) {
	//std::cout << "Parameterized constructor called by <RPN>" << std::endl;

	std::istringstream	iss(inp);
	std::string			data;

	while (std::getline(iss, data, ' ')) {
		if (!data.empty()) {
			switch (int res = intepret(data)) {
				case '+':
				case '-':
				case '*':
				case '/':
					calculate(res);
					break ;

				case 10:
					clear();
					std::cout << "Error" << std::endl;
					exit(1);

				default:
					_number.push(res);
					break ;
			}
			// printf( "`%s'\n", data.c_str() );
		}
	}
}

RPN::RPN(const RPN &inp) {
	//std::cout << "Copy constructor called by <RPN>" << std::endl;
	*this = inp;
}

RPN::~RPN(void) {
	//std::cout << "Destructor called by <RPN>" << std::endl;
	if (_number.size() == 1)
		std::cout << _number.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
	clear();
}

RPN &RPN::operator= (const RPN &inp) {
	//std::cout << "Copy assignment operator called by <RPN>" << std::endl;
	this->_number = inp._number;
	return (*this);
}
