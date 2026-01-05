/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:51:58 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 15:18:35 by asbouani         ###   ########.fr       */
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
    if (this != &other)
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