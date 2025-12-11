/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:27:16 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 14:58:10 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon&     _weapon;
        
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        
        void    attack(void);
};

#endif