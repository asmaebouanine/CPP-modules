/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:09:17 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:25 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

int main()
{
    PhoneBook pb;
    std::string command;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin , command);
        if (!std::cin)
            break ;
        if (command == "ADD")
            pb.addContact();
        else if (command == "SEARCH")
        {
            pb.displayContacts();

            std::cout << "Enter index to view: ";
            std::getline(std::cin, command);
            bool valid = true;
            for (size_t i = 0; i < command.length(); i++) {
                if (!std::isdigit(command[i])) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                std::cout << "Invalid input! Index must be a number.\n";
            else {
                std::stringstream ss(command);
                int index;
                ss >> index;
                pb.showContact(index);
            }
        }

        else if (command == "EXIT")
            break ;
        else
            std::cout << "Unknown command!\n";        
    }
    return 0;
}