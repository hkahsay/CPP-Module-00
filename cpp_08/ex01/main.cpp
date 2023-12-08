#include"Span.hpp"

int main()
{
	int n = 5;

	Span sp(n);
	std::vector<int> numbers;
	
	try{

		sp.addNumbers(numbers.begin(), numbers.end());
	}
	
	catch(Span::spanFullException e)
	{
		std::cout<< RED"Well... there was a problem; the Span is full!"RESET << std::endl;
		
	}
	sp.addNumber(34);
	sp.addNumber(4);
	std::cout << sp << std::endl;

    try {
		std::cout<< YELLOW"longestSpan: "<< sp.longestSpan()<<" "<<RESET << std::endl;

	} catch(Span::spanIsEmptyException e) {
		std::cout<< "Well... there was a problem; the Span is empty!" << std::endl;
	}
	try {
		std::cout<< BLUE"shortestSpan: "<< sp.shortestSpan()<<" "RESET << std::endl;

	} catch(Span::spanIsEmptyException e) {
		std::cout<< "Well... there was a problem; the Span is empty!" << std::endl;
	}


	return 0;
}
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;