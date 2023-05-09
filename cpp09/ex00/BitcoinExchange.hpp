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
# include <ctime>
# include <cmath>
# include <map>

class BitcoinExchange {
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string &inp);
	BitcoinExchange(const BitcoinExchange &inp);
	~BitcoinExchange(void);
	BitcoinExchange &operator= (const BitcoinExchange &inp);

	int		splitLine(const std::string &line);
	int		intepretLine(const std::string &line);
	void	setTable(const std::string &name);
	double	calculate();
	void	clear(void);

private:
	std::map<std::string, double>	_table;
	std::pair<std::string, std::string>	_curLine;
	// std::pair<std::string, double>	_curLine;
};

#endif
