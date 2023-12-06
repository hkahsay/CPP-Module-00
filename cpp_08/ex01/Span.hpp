#ifndef SPAN_HPP
# define SPAN_HPP


#include<iostream>
#include<vector>

class Span 
{
	private:
		unsigned int _maxNum;
		std::vector<int>	_container;
		Span();//private 
	public:
	~Span();
	Span(unsigned int N);
	std::vector<int> getContainer()const;
	unsigned int getMaxNum()const;
	void	setContainer(std::vector<int> setcont);
	Span(Span const & src);
	Span& operator = (Span const &rhs);
	void	addNumber(unsigned int toBeAdd);
	void	addNumbers(std::vector<int> addnum);
	void 	displaycontainer(std::ostream& os)const;
	int		longestSpan();//std::vector<int> longspan
	void	shortestSpan();

};

std::ostream& operator<<(std::ostream& os, Span const& rhs);

#endif