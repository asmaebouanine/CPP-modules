/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:14:29 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/06 11:17:56 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& cont, int n)
{
    typename T::iterator it;
    it = std::find(cont.begin(), cont.end(), n);
    if (it == cont.end())
        throw std::exception();
    return it;
};
#endif