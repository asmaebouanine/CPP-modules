/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:56:17 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 21:17:52 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* a;
    a = src->createMateria("ice");
    me->equip(a);
    AMateria* b;
    b = src->createMateria("cure"); 
    me->equip(b);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->unequip(0);
    me->use(0, *bob);

    delete a;
    delete bob;
    delete me;
    delete src;

    return 0;
}
