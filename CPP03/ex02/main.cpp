/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:30:59 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/29 22:56:06 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// #include "ScavTrap.hpp"

int main(void)
{
    std::cout << "-----------STRAT-----------" << std::endl;
    
    FragTrap robotA("L");
    std::cout << "\n=== SPECIAL ABILITY ===" << std::endl;
    robotA.highFivesGuys();
    
    std::cout << "\n=== ATTACK ===" << std::endl;
    robotA.attack("Target");
    
    std::cout << "\n=== DAMAGE ===" << std::endl;
    robotA.takeDamage(40);
    robotA.takeDamage(60);
    robotA.attack("Target");

    std::cout << "\n=== REPAIR ===" << std::endl;
    robotA.beRepaired(10);

    FragTrap robotB("KIRA");

    std::cout << " \n=== ENERGY EXHAUSTION ===" << std::endl;
    for (int i = 0; i < 100; i++)
        robotB.attack("Target");
    robotB.attack("Target");
    
    std::cout << "\n=== REPAIR ENERGY ===" << std::endl;
    FragTrap robotC("RYUK");
    for(int i = 0; i < 105; i++)
        robotC.beRepaired(1);
    robotC.beRepaired(1);
    
    std::cout << "\n-----------END-----------" << std::endl;
  
    return 0;
}