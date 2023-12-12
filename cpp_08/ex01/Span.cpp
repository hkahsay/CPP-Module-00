#include"Span.hpp"

Span:: Span(): _maxNum(0)
{
	std::cout<<"default constructor"<<std::endl;
	return ;

}
Span:: ~Span()
{
	//std::cout<<"default destructor"<<std::endl;
	return ;


}

Span:: Span(unsigned int N): _maxNum(N)
{
	_container.reserve(N);
	return ;
}


Span:: Span(Span const &src): _maxNum(src._maxNum),_container(src.getContainer())
{
	*this = src;
	return ;

}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < rhs.getMaxNum(); i++)
		{
			this->_container[i] = rhs._container[i];
		}
		
	}
	return *this;
}

std::vector<int> Span:: getContainer() const
{
	return _container;
}

unsigned int Span:: getMaxNum() const
{
	return _maxNum;
}

void	Span:: addNumber(unsigned int toBeAdd)
{
	try
	{
		if (_maxNum <= _container.size()) throw Span::spanFullException();
		_container.push_back(toBeAdd);	
	}
	catch(Span:: spanFullException e)
	{
		std::cout<< RED"Well... there was a problem; the Span is full"RESET << std::endl;
	}
	
}

void	Span::setContainer(std::vector<int> setcont)
{
	_container = setcont;
}

// void	Span:: addNumbers(std::initializer_list<int> nums)
// {
// 	_container.insert(_container.end(), nums);

// }

/*
void	Span::addNumbers(std::vector<int> addnum)
{
	for (size_t i = 0; i < addnum.size(); i++)
	{
		_container.push_back(addnum[i]);
	}
}
*/

void Span::displaycontainer(std::ostream& os)const
{
	std::vector<int>::const_iterator itr;
	for (itr = _container.begin(); itr != _container.end(); itr++)
	{
		os<<*itr<< " ";
	}
	
}

int	Span::longestSpan()//std::vector<int> longspan
{

	if(_container.empty()) throw spanIsEmptyException();

	std::vector<int>::iterator it = std::max_element(_container.begin(), _container.end());
	std::vector<int>::iterator ite = std::min_element(_container.begin(), _container.end());
	if (it != _container.end() && ite != _container.end())
	{
		int	difference = *it - *ite;
		return difference;
	}
	else {
		return 0;
	}
}

int Span:: shortestSpan()
{
	if(_container.empty()) throw spanIsEmptyException();

	std::sort(_container.begin(),_container.end());
	// std :: adjacent_difference using custom function
	std::vector<int>	difference (_container.size() - 1);
    std::adjacent_difference(_container.begin(),_container.end(), difference.begin());
	std::vector<int>::iterator it = std::min_element(difference.begin(), difference.end());
    return *it;
}

std::ostream& operator<<(std::ostream& os, Span const& rhs)
{
	os << "Span: ";
	rhs.displaycontainer(os);
	
	return os;
}

char const * Span::spanIsEmptyException::what() const throw()
{
	return RED"Span is empty"RESET;
}

char const * Span::spanFullException::what() const throw()
{
	return RED"The span is full"RESET;
}
