/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:48:08 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/01 16:00:05 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap robotA("L");
    
    std::cout << "\n=== ATTACK ===" << std::endl;
    robotA.attack("MISA");

    std::cout << "\n=== DAMAGE ===" << std::endl;
    robotA.takeDamage(6);
    robotA.takeDamage(5);
    robotA.attack("MISA");
    
    std::cout << "\n=== REPAIR ===" << std::endl;
    robotA.beRepaired(3);
    ClapTrap robotB("KIRA");
    
    std::cout << "\n=== ENERGY EXHAUSTION ===" << std::endl;
    for(int i = 0; i <= 10; i++)
        robotB.attack("Criminals");
    robotB.attack("Criminals");
        
    std::cout << "\n=== REPAIR ENERGY ===" << std::endl;
    ClapTrap robotC("RYUC");
    for (int i = 0; i < 10; i++)
        robotC.beRepaired(3);
    robotC.beRepaired(3);
    
    return 0;    
}