/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:26:45 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 20:13:23 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat is created!" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat is copied!" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat is assigned!" << std::endl;
    WrongAnimal::operator=(other);
    return (*this);
}
void WrongCat::makeSound() const
{
    std::cout << "MEOW 🐱" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat is destroyed!" << std::endl;
}
