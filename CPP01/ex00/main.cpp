/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:53:46 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 18:09:44 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    randomChump("Bar");

    Zombie *Foo = newZombie("Foo");
    Foo->announce();
    delete Foo;
    
    return (0);
}