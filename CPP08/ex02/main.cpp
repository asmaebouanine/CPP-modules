/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:46:39 by asbouani          #+#    #+#             */
/*   Updated: 2026/04/11 18:01:16 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "=== MUTANTSTACK TEST ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout <<mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while(it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "==== LIST TEST ====" << std::endl;
    
    std::list<int> lst;

    lst.push_back(88);
    lst.push_back(4);
    lst.push_back(20);
    
    std::list<int>::iterator iter = lst.begin();
    std::list<int>::iterator iterat = lst.end();

    while (iter != iterat)
    {
        std::cout << *iter << std::endl;
        ++iter;
    }
    return 0;
}