/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:04:20 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 20:12:31 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat is created!" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat is copied!" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat is assigned!" << std::endl;
    Animal::operator=(other);
    return (*this);
}
void Cat::makeSound() const
{
    std::cout << "MEOW 🐱" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat is destroyed!" << std::endl;
}