#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <exception>

class Span {
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &span);
	~Span(void);
	Span &operator= (const Span &span);

	void	addNumber(int n);
	void	addNumber(int start, int end);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	std::vector<int>	getNumber(void) const;

private:
	unsigned int		_size;
	std::vector<int>	_number;
};

std::ostream &operator<< (std::ostream &os, const Span &span);

#endif
