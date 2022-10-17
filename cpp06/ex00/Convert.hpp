#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <cctype>
# include <locale>
# include <cmath>
# include <limits>

class Convert {
public:
	Convert(void);
	Convert(const char *convert);
	Convert(const Convert &convert);
	~Convert(void);
	Convert &operator= (const Convert &convert);

	void	printOutput(void);
	void	printOutput(const std::string &type);

private:
	char		*_src;
	bool		_isDouble;
	double		_double;
	float		_float;
	int			_int;
	char		_char;

	void	printCharOutput(void);
	void	printIntOutput(void);
	void	printFloatOutput(void);
	void	printDoubleOutput(void);
};

#endif
