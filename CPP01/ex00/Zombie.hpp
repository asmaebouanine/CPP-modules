/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:34:02 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/10 19:56:33 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif