/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:09:50 by asbouani          #+#    #+#             */
/*   Updated: 2025/12/11 17:42:11 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2){}
    
void    Replacer::replace()
{
    // 1. Open Input File
    std::ifstream inFile(_filename.c_str());
    if (!inFile.is_open())
    {
        std::cout << "Error: could not open input file." << std::endl;
        return ;
    }
    //open output file
    std::string outName = _filename + ".replace";
    std::ofstream outFile(outName.c_str());
    if (!outFile.is_open())
    {
        std::cout << "Error: could not create output file." << std::endl;
        inFile.close();
        return ;
    }
    //read the file line by line
    std::string line;
    
    while (std::getline(inFile, line))
    {
        size_t currentPos = 0;
        size_t foundPos = 0;
        // Loop to find all occurrences of s1 in the current line
        // line.find(str, pos) searches for 'str' starting from 'pos'
        while ((foundPos = line.find(_s1, currentPos)) != std::string::npos)
        {
            //write the text from currentPos up to where s1 was found
            outFile << line.substr(currentPos, foundPos - currentPos);
            //2. write s2(the replacement)
            outFile << _s2;
            //3.move our current position past the s1 we just found
            currentPos = foundPos + _s1.length();
        }
        //write the remainder of the line (text after last s1)
        outFile << line.substr(currentPos);
        //check if the line ended to avoiding adding an extra newline at the very end
        if (!inFile.eof())
            outFile << std::endl;
        //clean up
        inFile.close();
        outFile.close();
    }
    
    
}


