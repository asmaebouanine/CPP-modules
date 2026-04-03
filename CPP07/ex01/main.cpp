/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:54:10 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/03 21:25:03 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(const int &n)
{
    std::cout  << n << " ";
}
void increment(int &n)
{
    n += 2;
}
void printString(const std::string &s)
{
    std::cout << "Word: " << s << std::endl;
}
int main()
{
    std::string s[] = {"Hello", "C++", "ALICE", "HAH"};
    int n[] = {4, 2, 7, 9};
    int lenght = 4;
    
    std::cout << "=== PRINT NUMBERS ===" << std::endl; ;
    ::iter(n, lenght, printInt);
    std::cout << std::endl;
    
    ::iter(n, lenght, increment);
    
    std::cout << "\n=== UPDATED NUMBERS ===" << std::endl;;
    ::iter(n, lenght, printInt);
    std::cout << std::endl;
    
    std::cout << "\n=== PRINT WORDS ===" << std::endl;
    ::iter(s, lenght, printString);
}