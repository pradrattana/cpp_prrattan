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

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string &src) {
	if (this->setTable("data.csv"))
		this->init(src);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	// std::cout << "Copy constructor called by <BitcoinExchange>" << std::endl;
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void) {
	// std::cout << "Destructor called by <BitcoinExchange>" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator= (const BitcoinExchange &src) {
	// std::cout << "Copy assignment operator called by <BitcoinExchange>" << std::endl;
	this->_table = src._table;
	this->_curLine = src._curLine;
	return (*this);
}

int	BitcoinExchange::init(const std::string &inp) {
	std::fstream	ifs;
	std::string		data;

	if (!myOpenFile(ifs, inp, std::ios::in))
		return 0;

	if (std::getline(ifs, data)) {
		if (data == "date | value") {
			while (1) {
				if (!std::getline(ifs, data))
					break ;
				if (!data.empty()) {
					switch (intepretLine(data)) {
						case 0:
							std::cout << this->_curLine.first
								<< " => " << this->_curLine.second
								<< " = " << calculate()
								<< std::endl;
							break ;

						case 1:
							std::cout
								<< "Error: bad input => "
								<< data << std::endl;
							break ;

						case 2:
							std::cout
								<< "Error: not a positive number."
								<< std::endl;
							break ;

						case 3:
							std::cout
								<< "Error: too large a number."
								<< std::endl;
							break ;
					}
				}
			}
		} else {
			std::cout << "Error: invalid input file." << std::endl;
		}
	}

	ifs.close();
	return 1;
}

int	BitcoinExchange::setTable(const std::string &name) {
	std::fstream	ifs;
	std::string		data;
	std::pair<std::string, std::string>	pair;

	if (!myOpenFile(ifs, name, std::ios::in))
		return 0;

	if (std::getline(ifs, data)) {
		if (data == "date,exchange_rate") {
			while (1) {
				if (!std::getline(ifs, data)) {
					ifs.close();
					return 1;
				}
				if (!data.empty()) {
					if (!splitToPair(data, ",", pair))
						break ;
					if (!checkDate(pair.first))
						break ;
					this->_table.insert(pair);
				}
			}
		}
	}

	std::cout << "Error: invalid exchange rate file." << std::endl;
	ifs.close();
	return 0;
}

int	BitcoinExchange::intepretLine(const std::string &line) {
	if (!splitToPair(line, " | ", this->_curLine))
		return 1;
	if (!checkDate(this->_curLine.first))
		return 1;

	std::istringstream	iss(this->_curLine.second);
	double	val;

	iss >> val;
	if (!iss.eof())
		return 1;
	if (val < 0)
		return 2;
	if (val > 1000)
		return 3;
	return 0;
}

double	BitcoinExchange::calculate(void) const {
	std::pair<
		std::map<std::string, std::string>::const_iterator,
		std::map<std::string, std::string>::const_iterator
	>	res = this->_table.equal_range(this->_curLine.first);

	if (res.first == res.second && res.first != _table.begin())
		res.first--;
	return atof(this->_curLine.second.c_str())
		* atof(res.first->second.c_str());
}

int	myOpenFile(std::fstream &ifs, const std::string &name, std::ios::openmode flag) {
	ifs.open(name.c_str(), flag);
	if (!ifs.is_open()) {
		ifs.clear();
		std::cout << "Error: could not open file "
			<< name << std::endl;
		return 0;
	}
	return 1;
}

int	splitToPair(const std::string &line, const std::string &delim, std::pair<std::string, std::string> &pair) {
	// std::string::size_type	delimPos = line.find(delim);
	// std::string::size_type	delimRPos = line.rfind(delim);

	// if (delimPos == std::string::npos || delimPos != delimRPos)
	// 	return 0;
	// pair.first = line.substr(0, delimPos);
	// pair.second = line.substr(delimPos + delim.length());
	// return 1;

	std::string::size_type	delimPos = line.find(delim);

	if (delimPos == std::string::npos || delimPos != line.rfind(delim))
		return 0;
	
	std::string::size_type	notSpace = line.find_first_not_of(" ", 0, delimPos);
	std::string::size_type	notSpaceL = line.find_last_not_of(" ", delimPos - 1);
	pair.first = line.substr(notSpace, notSpaceL - notSpace + 1);

	notSpace = line.find_first_not_of(" ", delimPos + delim.length());
	notSpaceL = line.find_last_not_of(" ", line.length() - 1, line.length() - (delimPos + delim.length()));
	pair.second = line.substr(notSpace, notSpaceL - notSpace + 1);

	return 1;
}

int	checkDate(const std::string &date) {
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
	if (!iss.eof())
		return 0;

	struct tm	tm = {};
	tm.tm_year = y - 1900;
	tm.tm_mon = m - 1;
	tm.tm_mday = d;
	tm.tm_isdst = -1;

	std::mktime(&tm);
	return (tm.tm_year == y - 1900 && tm.tm_mon == m - 1
		&& tm.tm_mday == d);
}
