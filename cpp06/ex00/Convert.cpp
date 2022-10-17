#include "Convert.hpp"

Convert::Convert(void) {
	//std::cout << "Default constructor called by <Convert>" << std::endl;
}

Convert::Convert(const char *convert) {
	//std::cout << "Parameterized constructor called by <Convert>" << std::endl;
	this->_src = const_cast<char *>(convert);

	std::istringstream	stream(this->_src);
	double	num;
	stream >> num >> std::ws;
	this->_isDouble = (stream.eof() && !stream.fail());
	if (!this->_isDouble && stream.tellg() >= 0) {
		std::string	rem(stream.str().substr(stream.tellg()));
		this->_isDouble = (rem.compare("f") == 0);
	}
	

	this->_double = std::atof(this->_src);
	this->_float = static_cast<float>(this->_double);
	this->_int = std::atoi(this->_src);
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
	this->_src = convert._src;
	this->_double = convert._double;
	this->_float = convert._float;
	this->_int = convert._int;
	this->_char = convert._char;
	return (*this);
}

void	Convert::printOutput(void) {
	void	(Convert::*func[])(void) = {
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
		std::cout << cmp[i] << ": ";
		(this->*func[i])();
		std::cout << std::endl;
	}
}

void	Convert::printOutput(const std::string &type) {
	void	(Convert::*func[])(void) = {
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

	std::cout << type << ": ";
	for (int i = 0; i < 4; i++) {
		if (type.compare(cmp[i]) == 0) {
			(this->*func[i])();
			break ;
		}
	}
	std::cout << std::endl;
}

void	Convert::printCharOutput(void) {
	if (this->_isDouble
		&& this->_double >= 0
		&& this->_double <= std::numeric_limits<char>::max()) {
		if (std::isprint(this->_char)) {
			std::cout << "'" << this->_char << "'";
		} else {
			std::cout << "Non displayable";
		}
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printIntOutput(void) {
	if (this->_isDouble
		&& this->_int == static_cast<int>(this->_double)) {
		std::cout << this->_int;
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printFloatOutput(void) {
	if (this->_isDouble) {
		std::cout << std::fixed << std::setprecision(1) << this->_float;
		std::cout << "f";
	} else if (std::isnan(this->_float) || std::isinf(this->_double)) {
		std::cout << this->_float << "f";
	} else {
		std::cout << "impossible";
	}
}

void	Convert::printDoubleOutput(void) {
	if (this->_isDouble) {
		std::cout << std::fixed << std::setprecision(1) << this->_double;
	} else if (std::isnan(this->_double) || std::isinf(this->_double)) {
		std::cout << this->_double;
	} else {
		std::cout << "impossible";
	}
}
