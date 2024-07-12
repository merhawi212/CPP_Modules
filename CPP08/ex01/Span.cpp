#include "Span.hpp"


Span::Span(){}

Span::~Span(){}

Span::Span(const unsigned int size): _maxCapacity(size)
{

}


Span::Span(const Span & src){

	*this = src;
}

Span &Span::operator =(const Span & other){

	if (this != &other){
		this->_maxCapacity = other._maxCapacity;
		this->_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(const int toAdd){
	if ((this->_numbers.size() + 1) > this->_maxCapacity)
		throw SpaceAlreadyFullException();
	this->_numbers.push_back(toAdd);
	
}


void Span::addRange(std::vector<int>::iterator& begin, std::vector<int>::iterator& end) {
	if ((this->_numbers.size() + std::distance(begin, end)) > this->_maxCapacity)
		throw InsertionOutOfBoundException();
	while (begin != end) {
		_numbers.push_back(*begin);
		++begin;
	}
}

int Span::shortestSpan(){
	if (this->_numbers.size() <= 1)
		throw NoSpanFoundException();
	
	std::sort(_numbers.begin(), _numbers.end());
	std::vector<int> adjacent_diff(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), adjacent_diff.begin());
	unsigned int shortest = *std::min_element(++adjacent_diff.begin(), adjacent_diff.end());
	return (shortest);

}
int Span::longestSpan(){
	if (this->_numbers.size() <= 1)
		throw NoSpanFoundException();

	std::sort(_numbers.begin(), _numbers.end());
   return _numbers.back() - _numbers.front();
}

int Span::getMaxCapacity() const{
	return this->_maxCapacity;
}
std::vector<int> Span::getNumbers() const{
	return this->_numbers;
}

const char * Span::SpaceAlreadyFullException::what () const throw (){
	return ("SpaceAlreadyFullException: Storage is aready full!");
}
const char * Span::NoSpanFoundException::what () const throw (){
	return ("NoSpanFoundException: Either the storate has one value or it's empty!");
}

const char * Span::InsertionOutOfBoundException::what () const throw (){
	return ("InsertionOutOfBoundException: Either the range has more number of values than the storage or the index is out of bound.");
}