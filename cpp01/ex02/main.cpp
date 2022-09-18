# include <iostream>

int main() {
	std::string	brain("HI THIS IS BRAIN");
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "The memory address of the string variable: " << &brain << std::endl
	    << "The memory address held by stringPTR:	  " << stringPTR << std::endl
	    << "The memory address held by stringREF:	  " << &stringREF << std::endl
	    << std::endl
	    << "The value of the string variable:  " << brain << std::endl
	    << "The value pointed to by stringPTR: " << *stringPTR << std::endl
	    << "The value pointed to by stringREF: " << stringREF << std::endl;
}
