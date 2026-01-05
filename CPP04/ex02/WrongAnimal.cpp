/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:31:44 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 18:31:46 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal is created!" << std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type = other.type;
    std::cout << "WrongAnimal is copied!" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal is assigned!" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}
std::string WrongAnimal::getType() const
{
    return (type);
}
void WrongAnimal::makeSound() const
{
    std::cout << "Default WrongAnimal sound" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal is destroyed!" << std::endl;
}