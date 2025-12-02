/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:49 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/01 21:12:16 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class   Phonebook
{
    private:
        Contact contacts[8];
        int     oldest;
        int     count;
        
    public:
        Phonebook();
        
        void    addContact();
        void    displayContacts();
        void    showContact(int index);
};

#endif