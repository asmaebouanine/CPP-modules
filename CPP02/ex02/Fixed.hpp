/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 20:42:26 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/17 14:12:30 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _rawValue;
        static const int _fractionalBits;
    public:
        //orthodox canonical form
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        //Constructor
        Fixed(const int value);
        Fixed(const float value);
        //getter / setter
        int getRawBits(void) const;
        void setRawBits(int const raw);
        //conversions
        float toFloat(void) const;
        int   toInt(void) const;
        //comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other)  const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        //arithmetic operators
        Fixed operator+(const Fixed &other)  const;
        Fixed operator-(const Fixed &other)  const;
        Fixed operator*(const Fixed &other)  const;
        Fixed operator/(const Fixed &other)  const;
        //increment/decrement
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        //static Min/Max
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);        
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif