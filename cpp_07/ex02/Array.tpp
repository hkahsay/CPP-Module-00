
template<typename T>
Array<T>:: Array(): _myArray(NULL), _n(0)
{

}

template<typename T>
Array<T>:: Array(unsigned int n):_n(n)
{
	if(n > 0)
	{
		_myArray = new int[_n];
		std::cout<<_myArray[0]<<std::endl;
	}
}

template<typename T>
Array<T>:: Array(Array<T> const &src)
{
	*this == src;
	
}

template<typename T>
unsigned int Array<T>:: size(void)const
{
	return this->_n;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return *this;
	if(_myArray)
		delete _myArray;
	this->_n = rhs.size();
	this->_myArray = new T [this->_n];
	if (this != &rhs)
	{
		for (size_t i = 0; i < this->_n.size(); i++)
		{
			this->_myArray[i] = rhs._myArray[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>:: operator[](unsigned int index)
{
	if(index >= _n)
		throw std::out_of_range("the index is out of range enter a valid index!");
	return this->_myArray[index];
	
}

template<typename T>
Array<T>:: ~Array()
{

	delete[] _myArray;
}

// template<typename T>
// std::ostream&	operator<<(std::ostream& stream, Array<T> &rhs)
// {
// 	for (size_t i = 0; i < rhs.size(); ++i)
// 	{
// 		stream << i << " - " << rhs[i] << "\n";
// 	}
// 	return stream;
// }