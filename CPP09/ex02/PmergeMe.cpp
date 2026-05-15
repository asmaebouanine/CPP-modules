/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:26:06 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/14 18:28:38 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    _extra = 0;
    _hasExtra = false;
    _timeD = 0;
    
    _extraDeque = 0;
    _hasExtraDeque = false;
    _timeV = 0;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vector = other._vector;
    _pairs = other._pairs;
    _sortedPairs = other._sortedPairs;
    _extra = other._extra;
    _hasExtra = other._hasExtra;
    _timeV = other._timeV;
    
    _deque = other._deque;
    _pairsDeque = other._pairsDeque;
    _sortedPairsDeque = other._sortedPairsDeque;
    _extraDeque = other._extraDeque;
    _hasExtraDeque = other._hasExtraDeque;
    _timeD = other._timeD;
    
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _pairs = other._pairs;
        _sortedPairs = other._sortedPairs;
        _extra = other._extra;
        _hasExtra = other._hasExtra;
        _timeV = other._timeV;
        
        _deque = other._deque;
        _pairsDeque = other._pairsDeque;
        _sortedPairsDeque = other._sortedPairsDeque;
        _extraDeque = other._extraDeque;
        _hasExtraDeque = other._hasExtraDeque;
        _timeD = other._timeD;
        
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseInput(int ac, char **av)
{
    int i = 1;
    
    while (i < ac)
    {
        std::string input = av[i];
        if (input.empty())
            return 1;
        
        for (size_t j = 0; j < input.length(); j++)
        {
            if (!isdigit(input[j]))
                return 1;
        }

        long value = std::strtol(input.c_str(), NULL, 10);
        
        if (value < 0 || value > INT_MAX)
            return (1);
        
        _vector.push_back(value);
        _deque.push_back(value);
        i++;
    }
    return 0;
}

void PmergeMe:: printBefor() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

size_t jacobsthal(size_t index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
        
    size_t prev = 0;
    size_t curr = 1;
    
    for (size_t i = 2; i <= index; i++)
    {
        size_t nextValue;
        
        nextValue = curr + 2 * prev;
        prev = curr;
        curr = nextValue; 
    }
    return curr;
}

std::vector<size_t> jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    size_t index = 1;
    
    while (true)
    {
        size_t jCur = jacobsthal(index + 1);
        size_t jPrev = jacobsthal(index);
        
        if (jPrev >= n)
            break;
        
        size_t end; 
        
        if (jCur < n)
            end = jCur -1;
        else
            end = n - 1;
        
        size_t start = jPrev;
        
        for (size_t i = end + 1; i-- > start;)
            order.push_back(i);
        index++;
    }
    return order;
}

void PmergeMe::makePairs(std::vector<int>& v)
{
    _pairs.clear();
    _hasExtra = false;
    _extra = 0;
    
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        int a = v[i];
        int b = v[i + 1];
        if (a > b)
            std::swap(a, b);
        _pairs.push_back(std::make_pair(a, b));
    }
    if (v.size() % 2 == 1)
    {
        _extra = v[v.size() - 1];
        _hasExtra = true;
    }
}

void PmergeMe::sortVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;
    makePairs(v);

    std::vector<std::pair<int,int> > currentPairs = _pairs;
    int  currentExtra    = _extra;
    bool currentHasExtra = _hasExtra;

    std::vector<int> winners;
    for (size_t i = 0; i < currentPairs.size(); i++)
        winners.push_back(currentPairs[i].second); 
    sortVector(winners); 
    
    std::vector<std::pair<int,int> > sortedPairs(currentPairs.size());
    std::vector<bool> used(currentPairs.size(), false);
    
    for (size_t i = 0; i < winners.size(); i++)
    {
        for (size_t j = 0; j < currentPairs.size(); j++)
        {
            if (!used[j] && currentPairs[j].second == winners[i])
            {
                sortedPairs[i] = currentPairs[j];
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> chain;
    
    chain.push_back(sortedPairs[0].first);
    for (size_t i = 0; i < sortedPairs.size(); i++)
        chain.push_back(sortedPairs[i].second);
    std::vector<size_t> order = jacobsthalOrder(sortedPairs.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        if (idx == 0) 
            continue;

        int loser  = sortedPairs[idx].first;
        int winner = sortedPairs[idx].second;
      
        size_t limit = chain.size();
        for (size_t p = 0; p < chain.size(); p++)
        {
            if (chain[p] == winner)
            {
                limit = p;
                break;
            }
        }
        size_t pos = std::lower_bound(chain.begin(), chain.begin() + limit, loser) - chain.begin();
        chain.insert(chain.begin() + pos, loser);
    }
    
    if (currentHasExtra)
    {
        size_t pos = std::lower_bound(chain.begin(), chain.end(), currentExtra) - chain.begin();
        chain.insert(chain.begin() + pos, currentExtra);
    }
    v = chain;
}

void PmergeMe::makePairsDeque(std::deque<int>& d)
{
    _pairs.clear();
    _hasExtra = false;
    _extra = 0;
    
    for(size_t i = 0; i + 1 < d.size(); i += 2)
    {
        int a = d[i];
        int b = d[i + 1];
        if (a > b)
            std::swap(a, b);
        _pairs.push_back(std::make_pair(a, b));
    }
    if (d.size() % 2 == 1)
    {
        _extra = d[d.size() - 1];
        _hasExtra = true;
    }
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;
    makePairsDeque(d);
   
    std::vector<std::pair<int,int> > current_pairs = _pairs;
    int  current_extra    = _extra;
    bool current_hasExtra = _hasExtra;
    
    std::deque<int> winners;
    for (size_t i = 0; i < current_pairs.size(); i++)
        winners.push_back(current_pairs[i].second);  
    sortDeque(winners); 
    
    std::vector<std::pair<int,int> > sorted_pairs(current_pairs.size());
    std::vector<bool> used(current_pairs.size(), false);

    for (size_t i = 0; i < winners.size(); i++)
    {
        for (size_t j = 0; j < current_pairs.size(); j++)
        {
            if (!used[j] && current_pairs[j].second == winners[i])
            {
                sorted_pairs[i] = current_pairs[j];
                used[j] = true;
                break;
            }
        }
    }
  
    std::deque<int> chain;
    chain.push_back(sorted_pairs[0].first);
    for (size_t i = 0; i < sorted_pairs.size(); i++)
        chain.push_back(sorted_pairs[i].second);

    std::vector<size_t> order = jacobsthalOrder(sorted_pairs.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        if (idx == 0)
            continue;
        
        int loser  = sorted_pairs[idx].first;
        int winner = sorted_pairs[idx].second;
        
        size_t limit = chain.size();
        for (size_t p = 0; p < chain.size(); p++)
        {
            if (chain[p] == winner)
            {
                limit = p;
                break;
            }
        }
        size_t pos = std::lower_bound(chain.begin(), chain.begin() + limit, loser) - chain.begin();
        chain.insert(chain.begin() + pos, loser);
    }

    if (current_hasExtra)
    {
        size_t pos = std::lower_bound(chain.begin(), chain.end(), current_extra) - chain.begin();
        chain.insert(chain.begin() + pos, current_extra);
    }
    d = chain;
}

double getTimeSeconds()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec + ts.tv_nsec / 1e9);
}

void PmergeMe::sort()
{
    double start = getTimeSeconds();
    sortVector(_vector);
    _timeV = getTimeSeconds() - start;
    
    start = getTimeSeconds();
    sortDeque(_deque);
    _timeD = getTimeSeconds() - start;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printTime() const
{
    std::cout << std::fixed << std::setprecision(5);
    
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << _timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque  : " << _timeD << " us" << std::endl;
}
