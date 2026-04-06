/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:12:21 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/06 19:45:12 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0), _numbers(0) {}

Span::Span(unsigned int N) : _N(N), _numbers(0) {}

Span::Span(const Span& other)
{
    _N = other._N;
    _numbers = other._numbers;
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return (*this);
    _N = other._N;
    _numbers = other._numbers;
    return (*this);
}

void Span::addNumber(int value)
{
    if (_N == _numbers.size())
        throw (std::exception());
    _numbers.push_back(value);
}
int Span::shortestSpan() const
{
    int size = _numbers.size();
    int diff;
    if (size < 2)
        throw (std::exception());
    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    int shortSpan = copy[1] - copy[0];
    for (int i = 0; i < size - 1; i++)
    {
        diff = copy[i+1] - copy[i];
        if (diff < shortSpan)
            shortSpan = diff;
    }
    return (shortSpan);
}

int Span::longestSpan() const
{
    int size = _numbers.size();
    if (size < 2)
        throw (std::exception());
    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    int longSpan = copy[size - 1] - copy[0];
    return (longSpan);
}

Span::~Span() {}