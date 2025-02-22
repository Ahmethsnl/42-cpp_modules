#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedNumber = 0;
}

Fixed::Fixed(const int value)
{
	fixedNumber = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	fixedNumber = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	fixedNumber = fixed.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	return fixedNumber;
}

void Fixed::setRawBits(int const raw)
{
	fixedNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)fixedNumber / (1 << fractionalBits);
}

int		Fixed::toInt(void) const
{
	return fixedNumber >> fractionalBits;
}