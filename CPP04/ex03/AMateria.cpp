/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:09:04 by asbouani          #+#    #+#             */
/*   Updated: 2026/01/13 21:20:59 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        (void)other;
    return (*this);
}
std::string const& AMateria::getType() const
{
    return (_type);
}
void AMateria::use(ICharacter& target)
{
    (void)target;
}
AMateria::~AMateria() {}
