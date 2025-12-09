/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:42 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/09 17:29:33 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    oldest = 0;
    count = 0;
};
std::string PhoneBook::getInput(const std::string& prompt)
{
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Error! empty input.\n";
    } while (input.empty());
    return input;
}

void PhoneBook::addContact()
{
    contacts[oldest].setFirstName(getInput("First Name: "));
    contacts[oldest].setLastName(getInput("Last Name: "));
    contacts[oldest].setNickname(getInput("Nickname: "));
    contacts[oldest].setPhoneNumber(getInput("Phone Number: "));
    contacts[oldest].setDarketSecret(getInput("Darkest Secret: "));

    oldest = (oldest + 1) % 8;
    if (count < 8) count++;
}

std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + "."; 
    return str;
}
void    PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << std::endl;
              
    for(int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i
                  << "|" << std::setw(10) << truncate(contacts[i].getFirstName())
                  << "|" << std::setw(10) << truncate(contacts[i].getLastName())
                  << "|" << std::setw(10) << truncate(contacts[i].getNickname())
                  << std::endl;
    } 
}

void    PhoneBook::showContact(int index)
{
    if (index < 0 || index >= count){
        std::cout << "Invalid index!\n";
        return ;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Dark Secret: " << contacts[index].getDarketSecret() << std::endl;
}