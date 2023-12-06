#include"Span.hpp"
// Span:: Span(size_t size): _container(size)
// {

// }


Span:: Span(): _maxNum(0)
{
	std::cout<<"default constructor"<<std::endl;
	return ;

}
Span:: ~Span()
{
	std::cout<<"default destructor"<<std::endl;
	return ;


}

Span:: Span(unsigned int N): _maxNum(N)
{
	return ;
}


Span:: Span(Span const &src)
{
	*this = src;
	return ;

}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		// for (size_t i = 0; i < _maxNum; i++)
		// {
			_maxNum = rhs._maxNum;
			_container = rhs.getContainer();
		// }
		
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
	_container.push_back(toBeAdd);	
}
void	Span::setContainer(std::vector<int> setcont)
{
	_container = setcont;
}

// void	Span:: addNumbers(std::initializer_list<int> nums)
// {
// 	_container.insert(_container.end(), nums);

// }
void	Span::addNumbers(std::vector<int> addnum)
{
	for (size_t i = 0; i < addnum.size(); i++)
	{
		_container.push_back(addnum[i]);
	}
}

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
	if(!_container.empty())
	{
		std::vector<int>::iterator it = std::max_element(_container.begin(), _container.end());
		std::vector<int>::iterator ite = std::min_element(_container.begin(), _container.end());
		if (it != _container.end() && ite != _container.end())
		{
			int	difference = *it - *ite;
			std::cout<<"max_value: "<<*it<<std::endl;
			std::cout<<"min_value: "<<*ite<<std::endl;
			std::cout<<"longestspan: "<<difference<<std::endl;
			return difference;
		}
		else
			std::cout<<"error finding min / max element"<<std::endl;

	}
		
	else
		std::cout<<"there is no elements in the container"<<std::endl;
	return 0;
}


// void Span:: shortestSpan()
// {

// }

std::ostream& operator<<(std::ostream& os, Span const& rhs)
{
	os << "Span: ";
	rhs.displaycontainer(os);
	
	return os;
}
