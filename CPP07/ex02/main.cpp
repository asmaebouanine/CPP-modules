/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:53:39 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/03 22:58:24 by asbouani         ###   ########.fr       */
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
        A = A;
        std::cout << "A array size: "<< A.size() << std::endl;
        for (unsigned int i = 0; i < A.size(); i++)
            A[i] = i * 2;
        std::cout << "A in index 3: " << A[3] << std::endl;
        
        std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
        Array<int> copy(A);
        copy[4] = 88;
        std::cout << "A in index 4 after copy modified: " << A[4] << std::endl;
        std::cout << "Copy in index 4: " << copy[4] << std::endl;
        
        std::cout << "\n=== ASSIGNMENT OPERATOR === " << std::endl;
        Array<int> assigned;
        assigned = copy;
        assigned[4] = 123;
        std::cout << "assigned in index 4: " << assigned[4] << std::endl;
        std::cout << "copy in index 4 after assinged: " << copy[4] << std::endl;
        
        std::cout << "\n=== SELF-ASSIGMENT ===" << std::endl;
        assigned = assigned;
        std::cout << "selt-assigment: " << assigned[4] << std::endl;
        
        std::cout << "\n=== TEMPLATE WITH STRING ===" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "C++";
        words[2] = "HAH";
        for (unsigned int j = 0; j < words.size(); j++)
            std::cout << "Word: " << words[j] << std::endl;
            
        std::cout << "\n=== OUT OF BOUNDS ===" << std::endl;
        words[5] = "test";        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    } 
}