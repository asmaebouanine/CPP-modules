/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:38 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/01 18:20:41 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class  Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkeSecret;
    
    public:
        Contact();
        
        void setFirstName(const std::string& str);
        void setLastName(const std::string& str);
        void setNickname(const std::string& str);
        void setPhoneNumber(const std::string& str);
        void setDarkeSecret(const std::string& str);
    
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkeSecret();
};

#endif



