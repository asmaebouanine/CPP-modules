/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:32:01 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/20 15:01:46 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(float const x, float const y) : _x(x), _y(y){}

Point::Point(const Point &other) : _x(other._x), _y(other._y){}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}
Point::~Point(){}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const {return _y; }
