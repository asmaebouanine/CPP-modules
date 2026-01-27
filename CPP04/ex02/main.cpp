/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:20:31 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/12 11:43:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    delete i;
    delete j;
    
    std::cout << "\n--------------- Animal array -----------\n" << std::endl;
    Animal* animals[4];
 
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    for (int i = 0; i < 4; i++)
        delete animals[i];
    std::cout << "\n---------------Deep copy ------------\n" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "Sleep");

    Dog dog2 = dog1;
    dog2.setIdea(0, "Eat");

    std::cout << dog1.getIdea(0) << std::endl;
    std::cout << dog2.getIdea(0) << std::endl;
    
    return (0);
}