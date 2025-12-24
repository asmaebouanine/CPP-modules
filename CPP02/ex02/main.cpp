/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:20:48 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/24 18:20:59 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed       a;
    Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
   
    std::cout << b << std::endl;
    Fixed c(10);
    Fixed d(2);
    std::cout << c * d << std::endl;
    std::cout << c / d << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
  
    
    return 0;
}