/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:35:35 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/12 14:44:44 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _learnInventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._learnInventory[i])
            _learnInventory[i] = other._learnInventory[i]->clone();
        else
            _learnInventory[i] = NULL;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            delete _learnInventory[i];
        for (int i = 0; i < 4; i++)
        {
            if (other._learnInventory[i])
                _learnInventory[i] = other._learnInventory[i]->clone();
            else
                _learnInventory[i] = NULL;
        }
    }
    return (*this);
}
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
        if (_learnInventory[i] == m)
            return ;
    for (int i = 0; i < 4; i++)
    {
        if (_learnInventory[i] == NULL)
        {
            _learnInventory[i] = m;
            return ;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4; i++)
    {
        if (_learnInventory[i] && _learnInventory[i]->getType() == type)
            return _learnInventory[i]->clone();
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
   for (int i = 0; i < 4; i++)
        delete _learnInventory[i];
}
