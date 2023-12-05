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

	Span(Span const & src);
	Span& operator = (Span const &rhs);
	void	addNumber(unsigned int toBeAdd);
	// void	addNumbers(std::initializer_list<int> nums);
	void displaycontainer(std::ostream& os)const;

};

// std::ostream& operator<< (std::ostream& o, Span const &rhs);
std::ostream& operator<<(std::ostream& os, Span const& rhs);

#endif