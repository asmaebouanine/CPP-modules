/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:07:00 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/10 23:37:59 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t  value = reinterpret_cast<uintptr_t>(ptr);
    return value;
}
Data* Serializer::deserialize(uintptr_t raw)
{
    Data* value = reinterpret_cast<Data*>(raw);
    return value;
}
