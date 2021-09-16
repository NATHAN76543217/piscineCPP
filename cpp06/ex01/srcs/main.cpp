#include <string>
#include <iostream>

typedef	struct	s_data
{
	int		age;
}			Data;

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int		main()
{
	Data		data;
	Data		*unserialized;
	uintptr_t	serialized;

	std::cout << "Init value = 5" << std::endl;
	data.age = 5;
	serialized = serialize(&data);
	std::cout << "data address = " << &data << std::endl;
	std::cout << "serialized value = " << serialized << std::endl;
	unserialized = deserialize(serialized);
	std::cout << "unserialized addresse= " << unserialized << std::endl;
	if (unserialized == &data 
		&& data.age == unserialized->age)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	return EXIT_SUCCESS;
}