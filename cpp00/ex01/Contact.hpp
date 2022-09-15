#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

class Contact {
public:
	Contact(void);
	~Contact(void);
	void	setAttribute(int id);
	void	printAttribute(void);
	void	printRow(void);

private:
	int			_id;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
};

#endif
