/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:58:49 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/20 11:46:39 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>

int	myOpenFile(std::fstream &file, std::string name, std::ios::openmode flag) {
	file.open(name.c_str(), flag);
	if (!file.is_open())
		std::cout << name.c_str() << ": " << std::strerror(errno) << std::endl;
	return (file.is_open());
}

std::string	myReplaceLine(std::string line, std::string search, std::string replace) {
	std::string	str;

	if (search.length() > 0) {
		for (std::size_t find = line.find(search);
			find != std::string::npos; find = line.find(search))
		{
			str.append(line.substr(0, find));
			str.append(replace);
			line = line.substr(find + search.length());
		}
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

		if (!myOpenFile(in, filename, std::ios::in))
			return (1);
		if (!myOpenFile(out, filename + ".replace", std::ios::out)) {
			in.close();
			return (1);
		}
		while (std::getline(in, line))
			out << myReplaceLine(line, search, replace) << std::endl;
		in.close();
		out.close();
		return (0);
	}
	std::cout << "Error: Expected 3 arguments "
		<< "(filename, search_string, replace_string)" << std::endl;
	return (1);
}
