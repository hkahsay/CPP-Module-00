#include"iter.hpp"

int		main()
{
	std::string str[3];
	str[0] = "hello";
	str[1] = "world";
	str[2] = "2023";
	std::string strArray[] = { "Hello", "World", "C++","2023" };
	size_t	len = 3;
	size_t	size = 4;
	int	 array[3] = {1,2,3};
	iter(array, len, printValue<int>);
	iter(str, len, printValue<std::string>);
	iter(strArray, size,printValue<std::string>);

	return 0;

}
