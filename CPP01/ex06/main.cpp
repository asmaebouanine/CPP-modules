/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:21:20 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 21:34:02 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    { 
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    Harl harl;
    harl.complain(av[1]);
    return 0;
}