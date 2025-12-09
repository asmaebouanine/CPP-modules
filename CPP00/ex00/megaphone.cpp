/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:43:12 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:54 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for(int i = 1; ac > i; i++)
        {
            for(int j = 0; av[i][j]; j++)
                std:: cout << (char)(toupper(av[i][j]));
        }
         std:: cout << "\n";
    }
    else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
