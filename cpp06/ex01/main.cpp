#include <stdint.h>
#include <iostream>

struct	Data {
	std::string 	str;
	int				num;
};

uintptr_t	serialize(struct Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

int	main(void) {
/*
	struct Data		data;
	struct Data*	newData; // to see why it is undefined
	uintptr_t		rawData;

	data.raw = 1000;
	data.str = "Wake the fuck up, Samurai !";

	std::cout << "Data before serialize :" << std::endl << "- raw : "
	<< data.raw << std::endl << "- str : " << data.str << std::endl;

	std::cout << "Data address : " << &data << std::endl;
	
	rawData = serialize(&data);
	std::cout << "raw Data address : 0x" << rawData << std::endl;
	
	newData = deserialize(rawData);

	std::cout <<  "newData address : " << newData << std::endl;

	std::cout << "New Data after serialize :" << std::endl << "- raw : "
	<< newData->raw << std::endl << "- str : " << newData->str << std::endl;
*/

	struct Data	before;
	before.str = "Hello World";
	before.num = 99;

	std::cout << "Data before serialize" << std::endl
		<< "> address: " << &before << std::endl
		<< "> str    : " << before.str << std::endl
		<< "> num    : " << before.num << std::endl;

	uintptr_t	ret = serialize(&before);
	struct Data	*after = deserialize(ret);

	std::cout << std::endl;
	std::cout << "Data after deserialize" << std::endl
		<< "> address: " << after << std::endl
		<< "> str    : " << after->str << std::endl
		<< "> num    : " << after->num << std::endl;

	return (0);
}
