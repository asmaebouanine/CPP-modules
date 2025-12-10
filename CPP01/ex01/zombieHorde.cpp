/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:06:20 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 20:10:06 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N,std::string name)
{
    Zombie* horde;
    
    horde = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}