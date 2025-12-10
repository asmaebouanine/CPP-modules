/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:10:23 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 20:10:25 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie();

        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif