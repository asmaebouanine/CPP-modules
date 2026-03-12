/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:53:30 by asbouani          #+#    #+#             */
/*   Updated: 2026/03/12 20:02:16 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data myData;
    
    myData.name = "alice";
    myData.age = 20;
    myData.id = 44;
    
    Data*     originalPtr = &myData;
    uintptr_t serialized = Serializer::serialize(originalPtr);
    Data*     deserialisedPtr = Serializer::deserialize(serialized);  
    
    std::cout << "=== ORIGINAL DATA ===" << std::endl;
    std::cout << "Original ptr: " << originalPtr << std::endl;
    std::cout << "Name: " << myData.name << std::endl;
    std::cout << "Age: " << myData.age << std::endl;
    std::cout << "ID: " << myData.id << std::endl;
    
    std::cout << "\n=== DESERIALIZED DATA ===" << std::endl;
    std::cout << "Deserialized ptr: " << deserialisedPtr << std::endl;
    std::cout << "Name: " << deserialisedPtr->name << std::endl;
    std::cout << "Age: " << deserialisedPtr->age << std::endl;
    std::cout << "ID: " << deserialisedPtr->id << std::endl;
    
    if (originalPtr == deserialisedPtr)
        std::cout << "The addresses match prefectly!" << std::endl;
    else
        std::cout << "The addresses not do match!" << std::endl;   
}