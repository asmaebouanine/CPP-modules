/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:46:45 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 20:37:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog is created!" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain();
    *brain = *other.brain;
    std::cout << "Dog is copied!" << std::endl;
}
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog is assigned!" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);        
}
void Dog::makeSound() const
{
    std::cout << "WOOF 🐶" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog is destroyed!" << std::endl;
    delete brain;
}