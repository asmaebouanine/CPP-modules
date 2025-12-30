/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:46:10 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/29 19:17:28 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "---------START---------" << std::endl;
    ScavTrap robotA("L");
    std::cout << "\n==== SPECIAL ABILITY ====" << std::endl;
    robotA.guardGate();
    
    std::cout << "\n==== ATTACK ====" << std::endl;
    robotA.attack("Target");
    
    std::cout << "\n=== DAMAGE ====" << std::endl;
    robotA.takeDamage(50);
    robotA.takeDamage(50);
    robotA.attack("Target");
    
    std::cout << "\n==== REPAIR ====" << std::endl;
    robotA.beRepaired(10);
    
    ScavTrap robotB("KIRA");

    std::cout << "\n==== ENERGY EXHAUSTION ====" << std::endl;
    for(int i = 0; i < 50; i++)
        robotB.attack("Target");
    robotB.attack("Target");

    std::cout << "\n==== REPAIR ENERGY ====" << std::endl;
    ScavTrap robotC("RYUC");
    for (int i = 0; i < 50; i++)
        robotC.beRepaired(1);
    robotC.beRepaired(1);
    std::cout << "\n---------END---------" << std::endl;
    return 0;  
}