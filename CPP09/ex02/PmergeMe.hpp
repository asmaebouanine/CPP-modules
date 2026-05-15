/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:10 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/11 17:53:02 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>                    _vector;
        std::vector<std::pair<int, int> >   _pairs;
        std::vector<std::pair<int, int> >   _sortedPairs;
        int                                 _extra;
        bool                                _hasExtra;
        
        std::deque<int>                     _deque;
        std::deque<std::pair<int, int> >    _pairsDeque;
        std::deque<std::pair<int, int> >    _sortedPairsDeque;
        int                                 _extraDeque;
        bool                                _hasExtraDeque;
        
        double                              _timeV;
        double                              _timeD;
    
        void                sortVector(std::vector<int>& v);
        void                makePairs(std::vector<int>& v);
        std::vector<int>    buildChain();
        void                insertLosers(std::vector<int>& chain);
  
        void                sortDeque(std::deque<int>& d);
        void                makePairsDeque(std::deque<int>& d);
        std::deque<int>     buildchainDeque();
        void                insertLosersDeque(std::deque<int>& chain);
    
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        int     parseInput(int ac, char **av);
        void    printBefor() const;
        void    printAfter() const;
        void    sort();
        void    printTime() const;
};

#endif