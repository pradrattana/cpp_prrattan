/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:58:49 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/18 14:58:51 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	myOpenFile(std::fstream &file, std::string name, std::ios::openmode flag) {
	file.open(name.c_str(), flag);
	if (!file.is_open())
		throw "File couldn't be opened.";
}

std::string	myReplaceLine(std::string line, std::string search, std::string replace) {
	std::string		str;
	std::size_t		find;

	for (find = line.find(search); find != std::string::npos; find = line.find(search))
	{
		str.append(line.substr(0, find));
		str.append(replace);
		line = line.substr(find + search.length());
	}
	str.append(line);
	return (str);
}

int	main(int argc, char **argv) {
	if (argc == 4) {
		std::string		filename(argv[1]);
		std::string		search(argv[2]);
		std::string		replace(argv[3]);
		std::string		line;
		std::fstream	in;
		std::fstream	out;

		/*if (filename.length() == 0)
			throw "Filename is empty.";
		else if (search.length() == 0)
			throw "Search string is empty.";
		else if (replace.length() == 0)
			throw "Replace string is empty.";*/
		myOpenFile(in, filename, std::ios::in);
		myOpenFile(out, filename + ".replace", std::ios::out);
		while (std::getline(in, line))
			out << myReplaceLine(line, search, replace) << std::endl;
	}
	//else
	return (0);
}
