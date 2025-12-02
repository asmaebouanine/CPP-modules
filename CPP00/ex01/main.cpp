/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:09:17 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/02 14:47:25 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <sstream>

int main()
{
    Phonebook phonebook;
    std::string command;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin , command);
        if (!std::cin)
            break ;
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
        {
            phonebook.displayContacts();
            std::cout << "Enter index to view: ";
            std::getline(std::cin, command);
            std::stringstream ss(command);
            int index;
            ss >> index;
            phonebook.showContact(index);
        }
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Unknown command!\n";        
    }
    return 0;
}