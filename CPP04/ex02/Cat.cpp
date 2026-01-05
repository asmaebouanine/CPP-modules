/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:30:14 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 18:30:16 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat is created" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
    *brain = *other.brain;
    std::cout << "Cat copy constructor is called" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);
}
void Cat::makeSound() const
{
    std::cout << "MOEW" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
    delete brain;
}