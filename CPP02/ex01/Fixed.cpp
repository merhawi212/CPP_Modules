#include "Fixed.hpp"

Fixed::Fixed():_fixedPointValue(0)
{
    std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" <<std::endl;
    this->_fixedPointValue = value * (1 << _fractionalBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" <<std::endl;
    this->_fixedPointValue = (float)(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &another){
    std::cout << "Copy constructor called" <<std::endl;
    *this = another;
}

Fixed &Fixed::operator =(const Fixed &src){
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" <<std::endl;
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

 