/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:28:36 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/03 23:04:25 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>
#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
    _array = NULL;
    _n = 0;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    _n = n;
    _array = new T[n];
}
template<typename T>
Array<T>::Array(const Array& other)
{
    _n = other._n;
    if (_n == 0)
        _array = NULL;
    else
    {
        _array = new T[_n];
        for (size_t i = 0; i < _n; i++)
            _array[i] = other._array[i];
    }
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this == &other)
        return (*this);
    delete[] _array;
    _n = other._n;
    if (_n == 0)
        _array = NULL;
    else
    {
        _array = new T[_n];
        for (size_t i = 0; i < _n; i++)
            _array[i] = other._array[i];
    }
    return (*this);
}

template<typename T>
size_t Array<T>::size() const
{
    return _n;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _n)
        throw std::out_of_range("Index out of bounds");
    return (_array[index]);
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

#endif
