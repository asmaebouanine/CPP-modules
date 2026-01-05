/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:29:28 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/05 18:29:29 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "I have an idea";
    std::cout << "Brain is created" << std::endl;
}
Brain::Brain(const Brain& other)
{
    std::cout << "Brain is copied" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain is assigned" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}
Brain::~Brain()
{
    std::cout << "Brain is destroyed!" << std::endl;
}