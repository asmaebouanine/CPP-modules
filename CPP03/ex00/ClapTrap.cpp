/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:55:39 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/01 14:09:23 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "Default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " is copied!" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap " << _name << " is assigned!" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy or dead!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return ;
    }
    unsigned int hpValue = _hitPoints;
    if (amount > hpValue)
        _hitPoints = 0;
    else
        _hitPoints -= amount ;
    std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
     std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << " hit points!\n";
}
