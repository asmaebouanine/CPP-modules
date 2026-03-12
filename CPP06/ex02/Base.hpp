/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:58:00 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/12 21:32:40 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif