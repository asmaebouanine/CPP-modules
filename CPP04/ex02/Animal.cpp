/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:19:24 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 16:18:46 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
    type = "Animal";
    std::cout << "Animal is created!" << std::endl;
}
Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal is copied!" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal is copied!" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}
std::string Animal::getType() const
{
    return (type);
}
Animal::~Animal()
{
    std::cout << "Animal is destroyed!" << std::endl;
}