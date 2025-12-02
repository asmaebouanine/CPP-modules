/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:20:33 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/01 17:08:36 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){}

//setters
void Contact::setFirstName(const std::string& str)      {firstName = str;}
void Contact::setLastName(const std::string& str)       {lastName = str;}
void Contact::setNickname(const std::string& str)       {nickname = str;}
void Contact::setPhoneNumber(const std::string& str)    {phoneNumber = str;}
void Contact::setDarkeSecret(const std::string& str)    {darkeSecret = str;}

//getters
 std::string Contact::getFirstName()    {return firstName;}
 std::string Contact::getLastName()     {return lastName;}
 std::string Contact::getNickname()     {return nickname;}
 std::string Contact::getPhoneNumber()  {return phoneNumber;}
 std::string Contact::getDarkeSecret()  {return darkeSecret;}
 
