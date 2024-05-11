
#include "Array.hpp"

template <class T>

Array<T>::Array() : _size(0) {
	_array = new T[_size];
}

template <class T>
Array<T>::~Array() {
    delete[] _array;
}

template <class T>
Array<T>::Array(const Array& src)  {
    this->_array = NULL;
	*this = src;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& another) {
	if (this->_array)
		 delete[] _array;
    if (this != &another) {
        _size = another._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = another._array[i];
        }
    }
    return *this;
}

template <class T>
Array<T>::Array(size_t n) : _size(n) {
    _array = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = T();
    }
}

template <class T>
const char* Array<T>::IndexOutOfBoundException::what() const throw(){
	return ("IndexOutOfBoundException: Index out of range!");
}

template <class T>
size_t Array<T>::size() const{
	return _size;
}

template <class T>
T &Array<T>::operator [](size_t n) const{
	if (n >= _size ){
		 throw IndexOutOfBoundException();  // Throw IndexOutOfBoundException when index is out of bounds
	}
	return (_array[n]);

}

template <class T>
std::ostream& operator<<( std::ostream& out, const Array<T>& array ) {
    out << "{\"array\": \t[\n\t";
    for ( size_t i = 0 ; i < array.size(); i++ ) {
        out << array[i];
        if (i < array.size() - 1)
            out << ", ";
    }
    out << "\n ]\n}";
    return out;
}