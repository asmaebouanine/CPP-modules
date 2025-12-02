/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:42 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/02 15:16:54 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip> 

Phonebook::Phonebook() : oldest(0), count(0) {}

// Add a new contact
void    Phonebook::addContact()
{
    std::string input;
    
    std::cout << "First Name: ";
    std::getline(std::cin, input);
    contacts[oldest].setFirstName(input);
    
    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    contacts[oldest].setLastName(input);
    
    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    contacts[oldest].setNickname(input);
    
    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    contacts[oldest].setNickname(input);
    
    std::cout << "Dark secret: ";
    std::getline(std::cin, input);
    contacts[oldest].setDarkeSecret(input);
    
    oldest = (oldest + 1) % 8;
    if (count < 8) count++;
}
// Display table of contacts
void    Phonebook::displayContacts()
{
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << std::endl;
              
    for(int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i
                  << "|" << std::setw(10) << contacts[i].getFirstName().substr(0, 10)
                  << "|" << std::setw(10) << contacts[i].getLastName().substr(0, 10)
                  << "|" << std::setw(10) << contacts[i].getNickname().substr(0, 10)
                  << std::endl;
    } 
}
// show full contact by index
void    Phonebook::showContact(int index)
{
    if (index < 0 || index >= count){
        std::cout << "Invalid index!\n";
        return ;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Dark Secret: " << contacts[index].getDarkeSecret() << std::endl;
}