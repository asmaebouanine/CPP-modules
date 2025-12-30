/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:08 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/29 19:14:35 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "---------START---------" << std::endl;
    ClapTrap robotA("L");
    std::cout << "\n=== ATTACK ===" << std::endl;
    robotA.attack("Target");
    
    std::cout << "\n=== DAMAGE ===" << std::endl;
    robotA.takeDamage(4);
    robotA.takeDamage(5);
    robotA.attack("Target");
    
    std::cout << "\n=== REPAIR ===" << std::endl;
    robotA.beRepaired(3);
    ClapTrap robotB("KIRA");
    
    std::cout << "\n=== ENERGY EXHAUSTION ===" << std::endl;
    for(int i = 0; i <= 10; i++)
        robotB.attack("Target");
        
    std::cout << "\n=== REPAIR ENERGY ===" << std::endl;
    ClapTrap robotC("RYUC");
    for (int i = 0; i < 10; i++)
        robotC.beRepaired(1);
    robotC.beRepaired(1);
    std::cout << "\n---------END---------" << std::endl;
    
    return 0;    
}