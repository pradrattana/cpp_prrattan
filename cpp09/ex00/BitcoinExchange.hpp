/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <map>

class BitcoinExchange {
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string &src);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange(void);
	BitcoinExchange &operator= (const BitcoinExchange &src);

	int		init(const std::string &inp);
	int		setTable(const std::string &name);
	int		intepretLine(const std::string &line);
	double	calculate(void) const;

private:
	std::map<std::string, std::string>	_table;
	std::pair<std::string, std::string>	_curLine;
};

int	myOpenFile(std::fstream &ifs, const std::string &name, std::ios::openmode flag);
int	splitToPair(const std::string &line, const std::string &delim, std::pair<std::string, std::string> &pair);
int	checkDate(const std::string &date);

#endif
