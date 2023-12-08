#ifndef SPAN_HPP
# define SPAN_HPP


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cstdlib>
#include<random>


# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define VIOLET		"\033[0;36m"
# define RESET			"\033[0m"

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
		//void	addNumbers(std::vector<int> addnum);

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);

		void 	displaycontainer(std::ostream& os)const;
		int		longestSpan();//std::vector<int> longspan
		int		shortestSpan();
		class spanIsEmptyException: public std::exception
		{
			public:

			virtual char const * what() const throw();
		

		};
		class spanFullException: public std::exception
		{
			public:

			virtual char const * what() const throw();
		

		};


};

std::ostream& operator<<(std::ostream& os, Span const& rhs);

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	std::cout<<"_container.size() "<<_container.size()<< "this->getMaxNum()"<<this->getMaxNum()<<std::endl;
	std::random_device random;
	std::mt19937 randNumGenerator(random());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 50);
	for(unsigned int i = 0; i < this->getMaxNum(); ++i) {
		int randomnum = dist6(randNumGenerator);
		_container.push_back(randomnum);//rand()
	}
	if (!_container.empty() && _container.size() > this->getMaxNum()) throw Span::spanFullException();

	_container.insert(_container.end(), begin, end);
	
}

#endif