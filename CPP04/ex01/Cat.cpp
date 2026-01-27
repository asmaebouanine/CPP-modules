/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:46:05 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 20:14:43 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat is created!" << std::endl;
    brain = new Brain();
}
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat is copied!" << std::endl;
    brain = new Brain();
    *brain = *other.brain;
}
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat is assigned!" << std::endl;
   if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain();
        *brain = *other.brain;
    }
    return (*this);
}
void Cat::makeSound() const
{
    std::cout << "MOEW 🐱" << std::endl;
}
void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}
std::string Cat::getIdea(int index) const
{
    return (brain->getIdea(index));
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Cat is destroyed" << std::endl;
}