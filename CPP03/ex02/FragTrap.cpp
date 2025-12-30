/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:38:58 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/28 20:48:06 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is born!" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " is copied!" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap " << _name << " is assigned!" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other); 
    }
    return (*this);
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " is out of energy or dead!" << std::endl;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;

}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " requests a positive high five! 🙌" << std::endl;
}