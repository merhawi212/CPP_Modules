#include "Fixed.hpp"

Fixed::Fixed():_fixedPointValue(0)
{
}

Fixed::~Fixed(){

}

Fixed::Fixed(const int value)
{

    this->_fixedPointValue = value * (1 << _fractionalBits);

}

Fixed::Fixed(const float value)
{
    this->_fixedPointValue = (roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &another){
    *this = another;
}

Fixed &Fixed::operator =(const Fixed &src){
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator >=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator <=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator ==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator !=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}


float Fixed::operator +(const Fixed &other) const {
    return this->_fixedPointValue / ( 1 << _fractionalBits) + other._fixedPointValue  / ( 1 << _fractionalBits);
}

float Fixed::operator -(const Fixed &other) const {
    return this->_fixedPointValue / ( 1 << _fractionalBits) - other._fixedPointValue / ( 1 << _fractionalBits);
}

float Fixed::operator *(const Fixed &other) const {
    return (float)(this->_fixedPointValue) / ( 1 << _fractionalBits) 
            * (float)(other._fixedPointValue) / ( 1 << _fractionalBits);
}

float Fixed::operator / (const Fixed &other) const {
    return (this->_fixedPointValue / ( 1 << _fractionalBits)) / (other._fixedPointValue / ( 1 << _fractionalBits));
}

Fixed& Fixed::operator++() {
    this->_fixedPointValue += 1 ;
    return *this;
}

Fixed Fixed::operator++(int) {
   Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
   Fixed temp = *this;
    --(*this);
    return temp;
}

 Fixed&  Fixed::min(Fixed &first, Fixed &second){
    if (first.getRawBits() < second.getRawBits())
        return first;
    return second;
 }
 const Fixed&  Fixed::min(const Fixed &first, const Fixed &second){
    if (first.getRawBits() < second.getRawBits())
        return first;
    return second;
 }

 Fixed&  Fixed::max(Fixed &first, Fixed &second){
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
 }

 const Fixed&  Fixed::max(const Fixed &first, const Fixed &second){
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
 }

int Fixed::getRawBits( void ) const{
    return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ){
    this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const{
    return (float)(_fixedPointValue) / ( 1 << _fractionalBits);
}

int Fixed::toInt( void ) const{
       return (int)(roundf((float)(_fixedPointValue) / (1 << _fractionalBits)));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}

