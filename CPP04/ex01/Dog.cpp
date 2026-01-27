/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:46:45 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 20:15:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog is created!" << std::endl;
    brain = new Brain();
}
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog is copied!" << std::endl;
    brain = new Brain();
    *brain = *other.brain;
}
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog is assigned!" << std::endl;
   if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
    }
    return (*this);        
}
void Dog::makeSound() const
{
    std::cout << "WOOF 🐶" << std::endl;
}
void Dog::setIdea(int index, const std::string& idea)
{
        brain->setIdea(index, idea);
}
std::string Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog is destroyed!" << std::endl;
}