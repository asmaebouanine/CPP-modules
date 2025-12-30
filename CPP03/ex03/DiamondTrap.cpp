/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:48:45 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/28 21:36:04 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
    _hitPoints = 100; //fragtrap
    _energyPoints = 50; // scavtrap
    _attackDamage = 30; //fragtrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator is called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    return (*this);
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap is destroyed!" << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "I am a DiamondTrap named: " << _name << std::endl;
    std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}