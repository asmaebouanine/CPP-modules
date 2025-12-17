/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:35:35 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/16 19:28:30 by asbouani         ###   ########.fr       */
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
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        Fixed(const int value);
        Fixed(const float value);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif