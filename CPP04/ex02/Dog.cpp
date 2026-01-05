/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:30:53 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 18:30:54 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog is created" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other)
{
    *brain = *other.brain;
    std::cout << "Dog copy constructor is called" << std::endl;
}
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog copy assignment operator is called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);        
}
void Dog::makeSound() const
{
    std::cout << "WOOF" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
    delete brain;
}