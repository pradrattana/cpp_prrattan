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
	double		temp = atof(src);

	this->_double = temp;
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);

	if (convert.length() > 1 && !(isnan(temp) || isinf(temp))) {
		int	i = 0;
		if (*src == '+' || *src == '-')
			i++;
		if (!isdigit(src[i]))
			this->_type = "string";
	}

	if (this->_type.empty()) {
		if (convert.length() == 1 && !isdigit(*src)) {
			this->_type = "char";
			this->_char = *src;
			this->_double = static_cast<double>(this->_char);
			this->_float = static_cast<float>(this->_char);
			this->_int = static_cast<int>(this->_char);
		} else if (convert.find(".") == std::string::npos
			&& temp >= std::numeric_limits<int>::min()
			&& temp <= std::numeric_limits<int>::max()) {
			this->_type = "int";
			this->_int = atoi(src);
			this->_double = static_cast<double>(this->_int);
			this->_float = static_cast<float>(this->_int);
			this->_char = static_cast<char>(this->_int);
		} else if (convert.find("f") != std::string::npos
			&& !(isinf(temp) && convert.find("inff") == std::string::npos)) {
			this->_type = "float";
			this->_float = static_cast<float>(temp);
			this->_double = static_cast<double>(this->_float);
			this->_int = static_cast<int>(this->_float);
			this->_char = static_cast<char>(this->_float);
		} else {
			this->_type = "double";
		}
	}
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
	this->_type = convert._type;
	this->_double = convert._double;
	this->_float = convert._float;
	this->_int = convert._int;
	this->_char = convert._char;
	return (*this);
}

const std::string	&Convert::getInputType(void) const {
	return (this->_type);
}

void	Convert::printCharOutput(void) const {
	if (this->_double >= 0
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
	if (this->_double >= std::numeric_limits<int>::min()
		&& this->_double <= std::numeric_limits<int>::max()) {
		std::cout << this->_int;
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printFloatOutput(void) const {
	if (this->_double >= -std::numeric_limits<float>::max()
		&& this->_double <= std::numeric_limits<float>::max()) {
		std::cout << std::fixed << this->_float << "f";
	} else if (isnan(this->_float) || isinf(this->_float)) {
		std::cout << this->_float << "f";
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printDoubleOutput(void) const {
	if (this->_double >= -std::numeric_limits<double>::max()
		&& this->_double <= std::numeric_limits<double>::max()) {
		std::cout << std::fixed << this->_double;
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

	os << "// input type: " << convert.getInputType() << std::endl;
	for (int i = 0; i < 4; i++) {
		os << cmp[i] << ": ";
		(convert.*func[i])();
		os << std::endl;
	}
    return (os);
}
