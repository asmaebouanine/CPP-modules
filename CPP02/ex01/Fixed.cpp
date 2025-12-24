/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:38:05 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/23 17:24:11 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawValue = value << _fractionalBits; 
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawValue = roundf(value *(1 << _fractionalBits)); 
}
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue)
{
    std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    _rawValue = other._rawValue;
    return (*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
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
    return (_rawValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
