/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:43:58 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 19:44:09 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
    
    std::cout << "\n=== WRONG TEST ===" << std::endl;
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    a->makeSound();
    
    delete c;
    delete a;
    
    return 0;
}