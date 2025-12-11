/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:45:48 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 14:49:53 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):_type(type){}

std::string& Weapon::getType(void)
{
    return (_type);
}

void Weapon::setType(std::string newType)
{
    _type = newType;
}
