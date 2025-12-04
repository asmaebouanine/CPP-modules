/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:49 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/04 15:43:58 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip> 

class   PhoneBook
{
    private:
        Contact contacts[8];
        int     oldest;
        int     count;
        
        std::string getInput(const std::string& prompt);

    public:
        PhoneBook();
        
        void    addContact();
        void    displayContacts();
        void    showContact(int index);
};

#endif