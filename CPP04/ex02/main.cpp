/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:20:31 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 21:23:08 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete i;
    delete j;
    
    std::cout << "---------------------------------" << std::endl;
    
    Animal* animals[4];
    //fill first half with dogs
    for (int h = 0; h < 2; h++)
        animals[h] = new Dog();
        
    for (int h = 2; h < 4; h++)
        animals[h] = new Cat();
     
    for (int h = 0; h < 4; h++)
        animals[h]->makeSound();
    //cleaning
    for (int h = 0; h < 4; h++)
        delete animals[h];
    std::cout << "---------------------------------" << std::endl;
    //deep copy proof
    //create basic dog
    Dog basic;
    //call copy constructor
    Dog tmp = basic;
}