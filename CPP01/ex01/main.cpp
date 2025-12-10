/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:11:46 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 20:14:18 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde;
    
    horde = zombieHorde(N, "Clone");
    for(int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}