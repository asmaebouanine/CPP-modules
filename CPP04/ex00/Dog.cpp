/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:11:07 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 19:47:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog is created!" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog is copied!" << std::endl;
}
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog is assigned!" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);        
}
void Dog::makeSound() const
{
    std::cout << "WOOF 🐶" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog is destroyed!" << std::endl;
}