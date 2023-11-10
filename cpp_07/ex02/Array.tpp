
template<typename T>
Array<T>:: Array(): _myArray(NULL), _n(0)
{

}

template<typename T>
Array<T>:: Array(unsigned int n):_n(n)
{
	if(n > 0)
	{
		_myArray = new T[_n];
	} else {
		_myArray = NULL;
	}
}

template<typename T>
Array<T>:: Array(Array<T> const &src)
{
	_n = src.size();
	_myArray = new T[_n];
	for (size_t i = 0; i < _n; i++)
	{
		_myArray[i] = src._myArray[i];
		// _myArray[i] = src[i];

	}
}


template<typename T>
Array<T>&	Array<T>::operator=(Array const  &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if(_myArray != NULL) {
		delete[] _myArray;
	}
	_n = rhs.size();
	_myArray = new T[_n];
	for (size_t i = 0; i < _n; i++)
	{
		_myArray[i] = rhs._myArray[i];
		// _myArray[i] = rhs[i];

	}
	return *this;
}

template<typename T>
T&	Array<T>:: operator[](unsigned int index)
{
	if (index >= 0 && index < _n)
	{
		return _myArray[index];
	}
	throw std::out_of_range("the index is out of range");
	
}

// template<typename T>
// const T&	Array<T>:: operator[](unsigned int index)
// {
// 	if (index >= 0 && index < _n)
// 	{
// 		return _myArray[index];
// 	}
// 	throw std::out_of_range("the index is out of range");
	
// }

template<typename T>
unsigned int Array<T>:: size()const
{
	return this->_n;
}

template<typename T>
Array<T>:: ~Array()
{
	if(_myArray != NULL) {
		delete[] _myArray;
	}
}
