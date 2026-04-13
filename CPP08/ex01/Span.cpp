/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 12:12:21 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/13 23:54:53 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <exception>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

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
        throw std::out_of_range("Span is full");
    _numbers.push_back(value);
}
int Span::shortestSpan() const
{
    int diff;
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");
    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    int shortSpan = copy[1] - copy[0];
    for (size_t i = 0; i < copy.size() - 1; i++)
    {
        diff = copy[i+1] - copy[i];
        if (diff < shortSpan)
            shortSpan = diff;
    }
    return (shortSpan);
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers");
    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    int longSpan = copy[copy.size() - 1] - copy[0];
    return (longSpan);
}

Span::~Span() {}