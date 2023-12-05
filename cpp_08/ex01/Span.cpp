#include"Span.hpp"


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

// void	Span:: addNumbers(std::initializer_list<int> nums)
// {
// 	_container.insert(_container.end(), nums);

// }


void Span::displaycontainer(std::ostream& os)const
{
	std::vector<int>::const_iterator itr;
	for (itr = _container.begin(); itr != _container.end(); itr++)
	{
		os<<*itr<< " ";
	}
	
}

// template<typename elem>
std::ostream& operator<<(std::ostream& os, Span const& rhs)
{
	rhs.displaycontainer(os);
	return os;
}

// void Span::displayOrder()
// {
//     int num;

//     std::cout<<std::endl<<"What are the numbers ";
//     // getline(std::cin,num);
//     // std::cout<<std::endl<<"What is the phone number on the order? ";
//     // std::cin>>phone;

//     std::cout<<std::endl<<"The name on the order is: "<<num<<".";
// }