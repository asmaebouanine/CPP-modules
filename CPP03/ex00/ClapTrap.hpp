/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:11:00 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/29 14:21:52 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
        
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap &other);
        ~ClapTrap();
        
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif 