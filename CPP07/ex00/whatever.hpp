/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:43:15 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/03 21:47:12 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &x, T &y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
};

template<typename T>
T min(T &x, T &y)
{
    if (x < y)
        return x;
    return y;
};

template<typename T>
T max(T &x, T &y)
{
    if (x > y)
        return x;
    return y;
};

#endif