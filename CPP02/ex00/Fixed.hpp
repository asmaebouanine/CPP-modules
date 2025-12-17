/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:10:56 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/16 17:28:13 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _rawValue;
        static const int _fractionalBits;
        
    public:
        Fixed();                                //default constructor
        Fixed(const Fixed &other);              //copy constructor
        Fixed &operator=(const Fixed &other);   //copy assignment
        ~Fixed();                               //destructor
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif