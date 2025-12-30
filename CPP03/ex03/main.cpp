/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:11:11 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/28 21:47:27 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    {
        std::cout << "=== TEST 1: CREATION AND IDENTIFY ===" << std::endl;
        DiamondTrap robotD("Monster");
        robotD.whoAmI();
        std::cout << "\n--- Destruction Order ---" << std::endl;
    }
    {
        std::cout << "\n=== TEST 2: STATS AND ABILITIES MIX ===" << std::endl;
        DiamondTrap dt("Hybrid");
        std::cout << "\nTesting Attack:" << std::endl;
        dt.attack("Target Dummy");
        std::cout << "\nTesting FragTrap Ability:" << std::endl;
        dt.highFivesGuys();
        std::cout << "\nTesting ScavTrap Ability:" << std::endl;
        dt.guardGate();
        std::cout << "\nEnergy Check (Should have 50):" << std::endl;
        for(int i = 0; i < 49; i++)
            dt.attack("Spam");
        std::cout << "Attempting 51st attack (Should FAIL):" << std::endl;
        dt.attack("Final Target");
        std::cout << "\n--- Destruction ---" << std::endl;
    }
    std::cout << "\nAll tests completed." << std::endl;
    return 0;
}