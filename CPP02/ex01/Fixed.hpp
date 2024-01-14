#ifndef FIXED_HPP
#define  FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

       
    public:
        Fixed();
        Fixed(const Fixed &another);
        Fixed &operator =(const Fixed &src);
        Fixed(const int value);
        Fixed(const float value);
		~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
