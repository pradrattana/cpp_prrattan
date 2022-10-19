/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:44 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void) {
	//std::cout << "Default constructor called by <Convert>" << std::endl;
}

Convert::Convert(const std::string &convert) {
	//std::cout << "Parameterized constructor called by <Convert>" << std::endl;
	const char	*src = convert.c_str();

	std::istringstream	stream(src);
	double	num;
	stream >> num >> std::ws;
	this->_isDouble = stream.eof();
	//this->_isDouble = (stream.eof() && !stream.fail());
	//if (!this->_isDouble && stream.tellg() >= 0) {
	//	std::string	rem(stream.str().substr(stream.tellg()));
	//	this->_isDouble = (rem.compare("f") == 0);
	//}

	this->_double = atof(src);
	this->_float = static_cast<float>(this->_double);
	this->_int = atoi(src);
	this->_char = static_cast<char>(this->_int);
}

Convert::Convert(const Convert &convert) {
	//std::cout << "Copy constructor called by <Convert>" << std::endl;
	*this = convert;
}

Convert::~Convert(void) {
	//std::cout << "Destructor called by <Convert>" << std::endl;
}

Convert &Convert::operator= (const Convert &convert) {
	//std::cout << "Copy assignment operator called by <Convert>" << std::endl;
	this->_isDouble = convert._isDouble;
	this->_double = convert._double;
	this->_float = convert._float;
	this->_int = convert._int;
	this->_char = convert._char;
	return (*this);
}

void	Convert::printCharOutput(void) const {
	if (this->_isDouble && this->_double >= 0
		&& this->_double <= std::numeric_limits<char>::max()) {
		if (isprint(this->_char)) {
			std::cout << "'" << this->_char << "'";
		} else {
			std::cout << "Non displayable";
		}
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printIntOutput(void) const {
	if (this->_isDouble && this->_double >= std::numeric_limits<int>::min()
		&& this->_double <= std::numeric_limits<int>::max()) {
		std::cout << this->_int;
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printFloatOutput(void) const {
	if (this->_isDouble) {
		std::cout << std::fixed << std::setprecision(1) << this->_float;
		std::cout << "f";
	} else if (isnan(this->_float) || isinf(this->_float)) {
		std::cout << this->_float << "f";
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printDoubleOutput(void) const {
	if (this->_isDouble) {
		std::cout << std::fixed << std::setprecision(1) << this->_double;
	} else if (isnan(this->_double) || isinf(this->_double)) {
		std::cout << this->_double;
	} else {
		std::cout << "impossible";
	}
}

std::ostream &operator<< (std::ostream &os, const Convert &convert) {
	void	(Convert::*func[])(void) const = {
		&Convert::printCharOutput,
		&Convert::printIntOutput,
		&Convert::printFloatOutput,
		&Convert::printDoubleOutput
	};
	std::string	cmp[] = {
		"char",
		"int",
		"float",
		"double"
	};
	for (int i = 0; i < 4; i++) {
		os << cmp[i] << ": ";
		(convert.*func[i])();
		os << std::endl;
	}
    return (os);
}
