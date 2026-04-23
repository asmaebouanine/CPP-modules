/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:58:45 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/23 10:21:21 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
    private:
        std::stack<int> _numbers;
        
    public:
        RPN();
        RPN(const RPN& other);
        RPN operator=(const RPN& other);
        ~RPN();
        
        int evaluate(std::stringstream &ss);

};

#endif