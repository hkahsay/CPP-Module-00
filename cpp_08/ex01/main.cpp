#include"Span.hpp"

int main()
{
	Span sp(5);

	int	arr[] = {8, 9, 6, 2, 3, 4};
	std::vector<int> newsetcontainer(arr, arr + sizeof (arr) / sizeof(arr[0]));
	sp.addNumbers(newsetcontainer);
	// sp.print();
	std::cout<<sp << std::endl;
	// sp.longestSpan();
	std::cout<< sp.longestSpan() << std::endl;


	return 0;
}
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;