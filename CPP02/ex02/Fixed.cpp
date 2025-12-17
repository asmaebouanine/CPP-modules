/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:28:21 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/17 14:54:25 by asbouani         ###   ########.fr       */
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
    return *this;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits){}

Fixed::Fixed(const float value) : _rawValue(roundf(value *(1 << _fractionalBits))){}
//getter
int Fixed::getRawBits(void) const
{
    return _rawValue;
}

void Fixed::setRawBits(int const raw)
{
    _rawValue = raw;
}
//conversions
float Fixed::toFloat(void) const
{
    return (float)_rawValue / (1 << _fractionalBits);
}
int Fixed::toInt(void) const
{
    return _rawValue << _fractionalBits;
}
//comparison operators
bool Fixed::operator>(const Fixed &other) const
{
    return _rawValue > other._rawValue;
}
bool Fixed::operator<(const Fixed &other) const
{
    return _rawValue < other._rawValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return _rawValue >= other._rawValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return _rawValue <= other._rawValue;
}
bool Fixed::operator==(const Fixed &other) const
{
    return _rawValue == other._rawValue;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return _rawValue != other._rawValue;
}
//arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_rawValue + other._rawValue);
    return result;
    
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_rawValue - other._rawValue);
    return result;
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long tmp = (long)_rawValue * (long)other._rawValue;
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(_rawValue / other._rawValue);
    return result;
}
//increment / decrement
Fixed &Fixed::operator++()
{
    _rawValue++;
    return *this; //++i
}
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _rawValue++; //i++
    return (temp);
}
Fixed &Fixed::operator--()
{
    _rawValue--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _rawValue--;
    return (temp);
}
//Min and Max
Fixed &Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}
const Fixed &Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
//insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}