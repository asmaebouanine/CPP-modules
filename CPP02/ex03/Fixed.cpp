/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:37:51 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/24 18:26:34 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0){}

Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue){}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _rawValue = other._rawValue;
    return (*this);
}
Fixed::~Fixed(){}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits){}

Fixed::Fixed(const float value) : _rawValue(roundf(value *(1 << _fractionalBits))){}

int Fixed::getRawBits(void) const
{
    return (_rawValue);
}
void Fixed::setRawBits(int const raw)
{
    _rawValue = raw;
}
float Fixed::toFloat(void) const
{
    float raw = _rawValue;
    return (raw / (1 << _fractionalBits));
}
int Fixed::toInt(void) const
{
    return (_rawValue << _fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (_rawValue > other._rawValue);
}
bool Fixed::operator<(const Fixed &other) const
{
    return (_rawValue < other._rawValue);
}
bool Fixed::operator>=(const Fixed &other) const
{
    return (_rawValue >= other._rawValue);
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (_rawValue <= other._rawValue);
}
bool Fixed::operator==(const Fixed &other) const
{
    return (_rawValue == other._rawValue);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (_rawValue != other._rawValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed   result;
    result._rawValue = _rawValue + other._rawValue;
    return (result);
    
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed   result;
    result._rawValue = _rawValue - other._rawValue;
    return (result);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed   result;
    long a = this->_rawValue;
    long b = other._rawValue;
    
    result._rawValue = (a * b) >> _fractionalBits;
    return (result);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed   result;
    long a = this->_rawValue;

    result._rawValue = (a << _fractionalBits) / other._rawValue;
    return (result);
}

Fixed &Fixed::operator++()
{
    _rawValue++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _rawValue++;
    return (tmp);
}
Fixed &Fixed::operator--()
{
    _rawValue--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _rawValue--;
    return (tmp);
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}
const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
