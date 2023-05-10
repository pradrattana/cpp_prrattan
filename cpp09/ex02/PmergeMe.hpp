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
# include <ctime>
# include <vector>
# include <deque>
# include <algorithm>

template <class T>
class PmergeMe {
public:
	PmergeMe(void) {};

	PmergeMe(const PmergeMe &inp) {
		*this = inp;
	};

	~PmergeMe(void) {};

	PmergeMe &operator= (const PmergeMe &inp) {
		//std::cout << "Copy assignment operator called by <PmergeMe>" << std::endl;
		this->_number = inp._number;
		return (*this);
	};

	int	init(int argc, char **argv) {
		for (int i = 1; i < argc; i++) {
			std::istringstream	iss(argv[i]);
			int					data;

			iss >> data;
			if (data < 0 || !iss.eof())
				return 0;
			_number.push_back(data);
		}
		return 1;
	}

	const T	&getNumber(void) const {
		return _number;
	}

	void	setNumber(T inp) {
		_number.swap(inp);
	};

	void	mergeDevide(void) {
		if (_number.size() < 6) {
			insertionSort();
			return ;
		}

		PmergeMe b;
		b.setNumber(T(_number.begin() + _number.size() / 2, _number.end()));
		_number.erase(_number.begin() + _number.size() / 2, _number.end());

		mergeDevide();
		b.mergeDevide();

		mergeCombine(b);
	};

	void	mergeCombine(PmergeMe &b) {
		T	merge;

		while (!(_number.empty() || b._number.empty())) {
			if (_number.front() < b._number.front()) {
				merge.push_back(_number.front());
				_number.erase(_number.begin());
			} else {
				merge.push_back(b._number.front());
				b._number.erase(b._number.begin());
			}
		}
		while (!_number.empty()) {
			merge.push_back(_number.front());
			_number.erase(_number.begin());
		}
		while (!b._number.empty()) {
			merge.push_back(b._number.front());
			b._number.erase(b._number.begin());
		}
		_number.swap(merge);
	};

	void	insertionSort(void) {
		for (typename T::iterator it = _number.begin();
				it != _number.end(); it++)
		{
			if (it != _number.begin()) {
				// std::cout << *(it - 1) << " " << *it << "\n";
				typename T::iterator	it2 = it;
				while (*(it2 - 1) > *it2) {
					//std::swap(*(it2 - 1), *it2);
					std::iter_swap(it2 - 1, it2);
					if (--it2 == _number.begin())
						break;
				}
			}
		}
	};

	float	getFuncProcessorTime(void (PmergeMe::*func)(void), PmergeMe &obj) {
		clock_t	t = clock();
		(obj.*func)();
		t = clock() - t;
		// return (float)t / CLOCKS_PER_SEC;
		return (float)t * 1000000 / CLOCKS_PER_SEC;
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
