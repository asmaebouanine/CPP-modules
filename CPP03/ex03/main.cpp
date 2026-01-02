/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:11:11 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/01 20:10:49 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap robotA("L");
	
	std::cout << "\n=== WHO AM I ===" << std::endl;
	robotA.whoAmI();
	std::cout << "\n=== ATTACK ===" << std::endl;
	robotA.attack("MISA");
	
	std::cout << "\n=== DAMAGE ===" << std::endl;
	robotA.takeDamage(44);
	robotA.takeDamage(56);
	robotA.attack("MISA");
	
	std::cout << "\n=== REPAIR ===" << std::endl;
	robotA.beRepaired(3);

	DiamondTrap robotB("KIRA");

	std::cout << "\n=== ENERGY EXHAUSTION ===" << std::endl;
	for(int i = 0; i < 50; i++)
		robotB.attack("Criminals");
	robotB.attack("Criminals");

	std::cout << "\n=== WHO AM I (second robot) ===" << std::endl;
	robotB.whoAmI();
	
	return 0;
}
