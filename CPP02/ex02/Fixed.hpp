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
        ~Fixed();

        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &another);
        Fixed &operator =(const Fixed &src);

        bool operator >(const Fixed &other) const;
        bool operator <(const Fixed &other) const;
        bool operator >=(const Fixed &other) const;
        bool operator <=(const Fixed &other) const;
        bool operator ==(const Fixed &other) const;
        bool operator !=(const Fixed &other) const;

        float operator +(const Fixed &other) const;
        float operator -(const Fixed &other) const;
        float operator *(const Fixed &other) const;
        float operator /(const Fixed &other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed &first, Fixed &second);
        static const Fixed& min(const Fixed &first, const Fixed &second);
        static Fixed& max(Fixed &first, Fixed &second);
        static const Fixed& max(const Fixed &first, const Fixed &second);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

};
  std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
