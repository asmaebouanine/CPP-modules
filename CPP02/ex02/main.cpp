/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:20:48 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/26 10:55:22 by asbouani         ###   ########.fr       */
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
   
    std::cout << Fixed::max(a, b) << std::endl;
  
    
    return 0;
}