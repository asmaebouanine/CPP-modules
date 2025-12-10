/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:44:17 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 20:03:23 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void    Zombie::setName(std::string name)
{
    _name = name;
}
Zombie::~Zombie()
{
    std::cout << _name << ": is dead." << std::endl;
}

