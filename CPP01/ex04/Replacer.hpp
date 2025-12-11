/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:57:29 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 17:40:51 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <fstream>

class   Replacer
{
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
        
    public:
        Replacer(std::string filename, std::string s1, std::string s2);
     
        
        void    replace();
};

#endif