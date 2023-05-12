/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/10/17 10:45:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <sys/time.h>
# include <vector>
# include <deque>

template <class T>
class PmergeMe {
public:
	PmergeMe(void) {};

	PmergeMe(const PmergeMe &src) {
		*this = src;
	};

	~PmergeMe(void) {};

	PmergeMe &operator= (const PmergeMe &src) {
		this->_number = src._number;
		return (*this);
	};

	int	init(int argc, char **argv) {
		std::istringstream	iss;
		int					data;

		for (int i = 1; i < argc; i++) {
			iss.clear();
			iss.str(argv[i]);
			iss >> data;
			if (data < 0 || !iss.eof())
				return 0;
			if (atoi(argv[i]) != data)
				return 0;
			this->_number.push_back(data);
		}
		return 1;
	}

	const T	&getNumber(void) const {
		return this->_number;
	}

	void	setNumber(const T &inp) {
		this->_number.clear();
		this->_number = inp;
	};

	void	mergeDevide(void) {
		if (this->_number.size() < 15) {
			this->insertionSort();
			return ;
		}

		PmergeMe	b;
		typename T::iterator	half(this->_number.begin() + this->_number.size() / 2);
		typename T::iterator	end(this->_number.end());

		b.setNumber(T(half, end));
		this->_number.erase(half, end);

		this->mergeDevide();
		b.mergeDevide();

		this->mergeCombine(b);
	};

	void	mergeCombine(PmergeMe &b) {
		T	merge;

		while (!(this->_number.empty() || b._number.empty())) {
			if (this->_number.front() < b._number.front()) {
				merge.push_back(this->_number.front());
				this->_number.erase(this->_number.begin());
			} else {
				merge.push_back(b._number.front());
				b._number.erase(b._number.begin());
			}
		}
		if (!this->_number.empty()) {
			merge.insert(merge.end(), this->_number.begin(), this->_number.end());
			this->_number.clear();
		}
		if (!b._number.empty()) {
			merge.insert(merge.end(), b._number.begin(), b._number.end());
			b._number.clear();
		}

		this->setNumber(merge);
		merge.clear();
	};

	void	insertionSort(void) {
		for (typename T::iterator it = this->_number.begin();
				it != this->_number.end(); it++)
		{
			if (it != this->_number.begin()) {
				typename T::iterator	it2 = it;
				while (*(it2 - 1) > *it2) {
					std::iter_swap(it2 - 1, it2);
					if (--it2 == this->_number.begin())
						break ;
				}
			}
		}
	};

	// https://stackoverflow.com/a/12722972
	double	getFuncProcessingTime(void (PmergeMe::*func)(void), PmergeMe &obj) {
		struct timeval	tvStart, tvStop;

		gettimeofday(&tvStart, 0);
		(obj.*func)();
		gettimeofday(&tvStop, 0);

		return (tvStop.tv_sec - tvStart.tv_sec) * 1000000L
				+ tvStop.tv_usec - tvStart.tv_usec;
	}

private:
	T	_number;
};

template <class T>
std::ostream &operator<< (std::ostream &os, const PmergeMe<T> &src) {
	T	num(src.getNumber());

	for (typename T::const_iterator itc = num.begin();
			itc != num.end(); itc++)
	{
		os << *itc << (itc + 1 != num.end() ?  ", " : "");
	}
	return (os);
}

#endif
