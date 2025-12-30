/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:38:19 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/29 19:50:13 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 50;
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << name << " is born!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " is copied!" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap " << _name << " is assigned!" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy or dead!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;

}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in the Gate keeper mode." << std::endl;
}