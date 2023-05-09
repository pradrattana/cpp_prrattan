/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:44 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:45 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	//std::cout << "Default constructor called by <BitcoinExchange>" << std::endl;
}

void	BitcoinExchange::clear(void) {
	// while (_number.size() > 0)
	// 	_number.pop();
}

void	BitcoinExchange::setTable(const std::string &name) {
	std::fstream	ifs(name.c_str(), std::ios::in);

	if (!ifs.is_open()) {
		ifs.clear();
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string		data;

	while (std::getline(ifs, data)) {
		if (!data.empty()) {
			std::string::size_type	delimPos = data.find(',');
			_table.insert(
				std::pair<std::string, double>(
					data.substr(0, delimPos), atof(data.substr(delimPos + 1).c_str())
				)
			);
			// std::cout << data.substr(0, delimPos) << ", "
			// 	<< atof(data.substr(delimPos + 1).c_str()) << "\n";
		}
	}
}

double	BitcoinExchange::calculate() {
	//return atof(_curLine.second.c_str()) * _table.lower_bound(_curLine.first)->second;

	std::pair<std::map<std::string, double>::const_iterator, std::map<std::string, double>::const_iterator>
		res = _table.equal_range(_curLine.first);
	if (res.first == res.second)
		res.first--;
	return atof(_curLine.second.c_str()) * res.first->second;
}

int checkDate(const std::string &date) {
	std::istringstream	iss(date);
	int		d, m, y;
	char	delim;

	if (date.length() != 10)
		return 0;
	iss >> y >> delim;
	if (!(iss.tellg() == 5 && delim == '-'))
		return 0;
	iss >> m >> delim;
	if (!(iss.tellg() == 8 && delim == '-'))
		return 0;
	iss >> d;
	if (!(iss.eof()))
		return 0;

	struct tm tm;
	tm.tm_year = y - 1900;
	tm.tm_mon = m - 1;
	tm.tm_mday = d;
	mktime(&tm);
	return (tm.tm_year == y - 1900 && tm.tm_mon == m - 1
		&& tm.tm_mday == d);
}

int	BitcoinExchange::intepretLine(const std::string &line) {
	(void)line;
	// if (_curLine.first.length() + _curLine.second.length() != line.length() - 3)
	// 	return 0;
	if (!splitLine(line))
		return 1;

	//std::cout << "check date: " << checkDate(_curLine.first) << "\n";
	if (!checkDate(_curLine.first))
		return 1;
	//std::cout << "date: " << _curLine.first << "\n";

	std::istringstream	iss(_curLine.second);
	double	val;
	iss >> val;
	// std::cout << "val:  " << val << "\n";
	// if (!iss.eof())
	// 	return 1;
	if (val < 0)
		return 2;
	if (val > 1000)
		return 3;
	return 0;
}

int	BitcoinExchange::splitLine(const std::string &line) {
	std::string::size_type	delimPos = line.find(" | ");
	std::string::size_type	delimRPos = line.rfind(" | ");
	if (delimPos == std::string::npos || delimPos != delimRPos)
		return 0;
	_curLine.first = line.substr(0, delimPos);
	_curLine.second = line.substr(delimPos + 3);
	return 1;
}

BitcoinExchange::BitcoinExchange(const std::string &inp) {
	//std::cout << "Parameterized constructor called by <BitcoinExchange>" << std::endl;

	setTable("data.csv");

	std::fstream	ifs(inp.c_str(), std::ios::in);
	if (!ifs.is_open()) {
		ifs.clear();
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string	data;
	while (std::getline(ifs, data)) {
		if (!data.empty()) {
			//std::cout << "data=" << (data) ;
			//std::cout << "intepret=" << intepretLine(data) << "\n";
			
			switch (intepretLine(data)) {
				case 0:
					std::cout << _curLine.first << " => " << _curLine.second << " = " << calculate() << std::endl;
					break ;

				case 1:
					std::cout << "Error: bad input => " << data << std::endl;
					break ;

				case 2:
					std::cout << "Error: not a positive number." << std::endl;
					break ;

				case 3:
					std::cout << "Error: too large a number." << std::endl;
					break ;
			}
			// printf( "`%s'\n", data.c_str() );
		}
	}

	// splitLine("2011-13-08 | 5");
	// std::cout << intepretLine("2011-13-08 | 5") << "\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &inp) {
	//std::cout << "Copy constructor called by <BitcoinExchange>" << std::endl;
	*this = inp;
}

BitcoinExchange::~BitcoinExchange(void) {
	//std::cout << "Destructor called by <BitcoinExchange>" << std::endl;

	// if (_number.size() == 1)
	// 	std::cout << _number.top() << std::endl;
	// else
	// 	std::cout << "Error" << std::endl;
	// clear();
}

BitcoinExchange &BitcoinExchange::operator= (const BitcoinExchange &inp) {
	//std::cout << "Copy assignment operator called by <BitcoinExchange>" << std::endl;
	this->_table = inp._table;
	return (*this);
}
