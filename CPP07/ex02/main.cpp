/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:53:39 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/05 19:45:20 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "=== DEFAULT CONSTRUCTOR ===" << std::endl;
        Array<int> empty;
        std::cout << "Empty array size: "<< empty.size() << std::endl;
        
        std::cout << "\n=== CONSTRUCTOR WITH SIZE ===" << std::endl;
        Array<int> A(5);
        std::cout << "Size of A: "<< A.size() << std::endl;
        for (unsigned int i = 0; i < A.size(); i++)
            A[i] = i * 2;
        std::cout << "A at index 3: " << A[3] << std::endl;
        
        std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
        Array<int> copy(A);
        copy[4] = 88;
        std::cout << "A at index 4 after modifying copy: " << A[4] << std::endl;
        std::cout << "Copy at index 4: " << copy[4] << std::endl;
        
        std::cout << "\n=== ASSIGNMENT OPERATOR === " << std::endl;
        Array<int> assigned;
        assigned = copy;
        assigned[4] = 123;
        std::cout << "Assigned at index 4: " << assigned[4] << std::endl;
        std::cout << "Copy at index 4 after assignment: " << copy[4] << std::endl;
        
        std::cout << "\n=== SELF-ASSIGNMENT ===" << std::endl;
        assigned = assigned;
        std::cout << "Value at index 4 in assigned: "  << assigned[4] << std::endl;
        
        std::cout << "\n=== TEMPLATE WITH STRING ===" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "C++";
        words[2] = "HAH";
        for (unsigned int j = 0; j < words.size(); j++)
            std::cout << "Word: " << words[j] << std::endl;
            
        std::cout << "\n=== OUT OF BOUNDS ===" << std::endl;
        words[5] = "Test";        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
}