/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:46:05 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 19:50:18 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat is created!" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
    *brain = *other.brain;
    std::cout << "Cat is copied!" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat is assigned!" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);
}
void Cat::makeSound() const
{
    std::cout << "MOEW 🐱" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
    delete brain;
}