/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:53:26 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/27 20:59:35 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== TEST 1 ===" << std::endl;
    try
    {
      Bureaucrat b("Alice", 44);
      Form f("taxForm", 44, 66);
      
      std::cout << b << std::endl;
      std::cout << f << std::endl;
      
      b.signForm(f);
      std::cout << f << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2 ===" << std::endl;
    try
    {
        Bureaucrat c("Bob", 3);
        Form e("testForm", 2, 2);
        
        std::cout << c << std::endl;
        std::cout << e << std::endl;
        
        c.signForm(e);
        std::cout << e << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "End of program" << std::endl;
}