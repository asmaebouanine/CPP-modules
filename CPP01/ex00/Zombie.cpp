/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:24:36 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 19:04:43 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
}
void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::~Zombie()
{
    std::cout << _name << ": is dead." << std::endl;
}


