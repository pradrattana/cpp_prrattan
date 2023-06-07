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
# include <string>
# include <sys/time.h>
# include <algorithm>
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
		this->_seq = src._seq;
		this->_pend = src._pend;
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
			this->_seq.push_back(data);
		}
		return 1;
	}

	const T	&getSequence(void) const {
		return this->_seq;
	}

	const T	&getPend(void) const {
		return this->_pend;
	}

	void	groupAndSortPair(void) {
		typename T::iterator	half(this->_seq.begin() + this->_seq.size() / 2);
		this->_pend.insert(this->_pend.begin(), half, this->_seq.end());
		this->_seq.erase(half, this->_seq.end());

		for (typename T::iterator it1 = this->_seq.begin(),
									it2 = this->_pend.begin();
				it1 != this->_seq.end();
				it1++, it2++)
		{
			if (*it1 < *it2)
				std::iter_swap(it1, it2);
		}
	}

	void	recursivelySortLarger(typename T::iterator lastSeq, typename T::iterator lastPend) {
		if (lastSeq == this->_seq.begin())
			return ;

		recursivelySortLarger(lastSeq - 1, lastPend - 1);
		for (typename T::iterator itS = lastSeq - 1, itP = lastPend - 1;
				itS != this->_seq.begin() && *itS < *(itS - 1);
				itS--, itP--)
		{
			std::iter_swap(itS - 1, itS);
			std::iter_swap(itP - 1, itP);
		}
	}

	int	jacobsthal(int n) {
		if (n == 0 || n == 1)
			return 2 * n;
		return 2 * jacobsthal(n - 2) + jacobsthal(n - 1);
	}

	void	partitonAndReversePend(void) {
		typename T::iterator	first = this->_pend.begin();
		typename T::iterator	last;
		int	n = 1;

		while ((last = first + jacobsthal(n)) < this->_pend.end()) {
			std::reverse(first, last);
			first = last;
			n++;
		}
		std::reverse(first, this->_pend.end());
	}

	typename T::iterator	binarySearch(typename T::iterator r, int x) {
		typename T::iterator	l = this->_seq.begin(), m;
		while (l <= r) {
			m = l + (r - l) / 2;

			if (x >= *(m - 1) && x <= *m) {
				return m;
			}

			if (x > *m)
				l = m + 1;
			else
				r = m - 1;
		}
		if (x < this->_seq.front())
			return this->_seq.begin();
		return this->_seq.end();
	}

	void	searchAndInsertPend(void) {
		typename T::iterator	r, pos;
		int	n = 1, tmp = 2;

		while (!this->_pend.empty()) {
			tmp += jacobsthal(n - 1) + jacobsthal(n);
			r = this->_seq.begin() + tmp;
			if (r > this->_seq.end())
				r = this->_seq.end();
			for (int i = 0; i < jacobsthal(n) && !this->_pend.empty(); i++) {
				pos = binarySearch(r, this->_pend.front());
				this->_seq.insert(pos, this->_pend.front());
				this->_pend.erase(this->_pend.begin());
			}
			n++;
		}
	}

	// void	binarySearchInsert() {
	// 	typename T::iterator	r, pos;
	// 	int	n = 1, tmp = 2;

	// 	while (1) {
	// 		tmp += jacobsthal(n - 1) + jacobsthal(n);
	// 		if ((r = this->_seq.begin() + tmp) >= this->_seq.end())
	// 			break ;
	// 		for (int i = 0; i < jacobsthal(n); i++) {
	// 			pos = binarySearch(r, this->_pend.front());
	// 			this->_seq.insert(pos, this->_pend.front());
	// 			this->_pend.erase(this->_pend.begin());
	// 		}
	// 		n++;
	// 	}
	// 	while (!this->_pend.empty()) {
	// 		pos = binarySearch(this->_seq.end(), this->_pend.front());
	// 		this->_seq.insert(pos, this->_pend.front());
	// 		this->_pend.erase(this->_pend.begin());
	// 	}
	// }

	// https://en.wikipedia.org/wiki/Merge-insertion_sort
	void	mergeInsertionSort(void) {
		groupAndSortPair();

		if (this->_seq.size() == this->_pend.size())
			recursivelySortLarger(this->_seq.end(), this->_pend.end());
		else
			recursivelySortLarger(this->_seq.end(), this->_pend.end() - 1);

		this->_seq.insert(this->_seq.begin(), this->_pend.front());
		this->_pend.erase(this->_pend.begin());

		partitonAndReversePend();
		searchAndInsertPend();
	}

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
	T	_seq;
	T	_pend;
};

template <class T>
std::ostream &operator<< (std::ostream &os, const PmergeMe<T> &src) {
	T	num(src.getSequence());

	for (typename T::const_iterator itc = num.begin();
			itc != num.end(); itc++)
	{
		os << *itc << (itc + 1 != num.end() ?  ", " : "");
	}
	return (os);
}

#endif
