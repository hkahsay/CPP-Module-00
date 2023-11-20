template<typename T>
/*create an empty array*/
Array<T>:: Array(void):_n(0), _myArray(NULL)
{

}
/*create n elements of an array array*/
template<typename T>
Array<T>::Array(unsigned int n): _n(n)
{
    if (n > 0)
    {
        _myArray = new T [_n];
    }
    else
        _myArray = NULL;
    
}

template<typename T>
Array<T>::Array(Array const & src)
{
   _n = src.size();
   _myArray = new T [_n];
   for (size_t i = 0; i < _n; i++)
   {
        _myArray[i] = src._myArray[i];
   }
   
}
/*return type classname operator and parameter 
the same as copy constructor
delete if there is an exsisting array so that
, modifying either the
original array or its copy after copying 
musn’t affect the other array*/
template<typename T>
Array<T>&  Array<T>:: operator = (Array const &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (_myArray != NULL)
    {
       delete[] _myArray;
    }
    _n = rhs.size();
    _myArray = new T [_n];
    for (size_t i = 0; i < _n; i++)
    {
        _myArray[i] =rhs._myArray[i];
    }
    return *this;
    
    
}
template<typename T>
unsigned int  Array<T>::size()const
{
    return _n;
}

template<typename T>
T& Array<T>:: operator[](unsigned int index)
{
    if (index >= 0 && index < _n)
    {
        return _myArray[index];
        /* code */
    }
 	throw std::out_of_range("the index is out of range");

    
}
/*delete if _myarray is created or allocated*/
template<typename T>
Array<T>:: ~Array()
{
    if(_myArray != NULL)
        delete[] _myArray;
}

template<typename T>
std::ostream&	operator<<(std::ostream& stream, Array<T> &rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
	{
		stream << i << " - " << rhs[i] << "\n";
	}
	return stream;
}