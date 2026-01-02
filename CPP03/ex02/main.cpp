/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:30:59 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/01 16:04:02 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{   
    FragTrap robotA("L");
    
    std::cout << "\n=== SPECIAL ABILITY ===" << std::endl;
    robotA.highFivesGuys();
    
    std::cout << "\n=== ATTACK ===" << std::endl;
    robotA.attack("MISA");
    
    std::cout << "\n=== DAMAGE ===" << std::endl;
    robotA.takeDamage(40);
    robotA.takeDamage(60);
    robotA.attack("MISA");

    std::cout << "\n=== REPAIR ===" << std::endl;
    robotA.beRepaired(3);

    FragTrap robotB("KIRA");

    std::cout << " \n=== ENERGY EXHAUSTION ===" << std::endl;
    for (int i = 0; i < 100; i++)
        robotB.attack("Criminals");
    robotB.attack("Criminals");
    
    std::cout << "\n=== REPAIR ENERGY ===" << std::endl;
    FragTrap robotC("RYUK");
    for(int i = 0; i < 100; i++)
        robotC.beRepaired(3);
    robotC.beRepaired(3);

    return 0;
}
