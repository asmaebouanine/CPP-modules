/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:26:06 by asbouani          #+#    #+#             */
/*   Updated: 2026/05/01 17:20:27 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _extra(0), _hasExtra(false), _extraDeque(0), _hasExtraDeque(false) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vector = other._vector;
    _extra = other._extra;
    _hasExtra = other._hasExtra;
    _deque = other._deque;
    _extraDeque = other._extraDeque;
    _hasExtraDeque = other._hasExtraDeque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _extra = other._extra;
        _hasExtra = other._hasExtra;
        _deque = other._deque;
        _extraDeque = other._extraDeque;
        _hasExtraDeque = other._hasExtraDeque;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

//INPUT / OUTPUT
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

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

// JACOBSTHAL
size_t jacobsthal(size_t k)
{
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    size_t a = 0;
    size_t b = 1;
    for (size_t i = 2; i <= k; i++)
    {
        size_t tmp;
        tmp = b + 2 * a;
        a = b;
        b = tmp; 
    }
    return  b;
}
std::vector<size_t> jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    size_t k = 1;
    while (true)
    {
        size_t jCur = jacobsthal(k + 1);
        size_t jPrev = jacobsthal(k);
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
        k++;
    }
    return order;
}
// VECTOR IMPLIMENTATION
void PmergeMe::makePairs(std::vector<int>& v)
{
    _pairs.clear();
    _hasExtra = false;
    _extra = 0;
    
    for(size_t i = 0; i + 1 < v.size(); i += 2)
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
    // 1. Populate the shared class attributes
    makePairs(v);
    // 2. SAVE STATE locally before recursion destroys the class attributes
    std::vector<std::pair<int,int> > current_pairs = _pairs;
    int  current_extra    = _extra;
    bool current_hasExtra = _hasExtra;
    // 3. Extract winners and recurse
    std::vector<int> winners;
    for (size_t i = 0; i < current_pairs.size(); i++)
        winners.push_back(current_pairs[i].second); 
    sortVector(winners); 
    // 4. Safely align pairs using a LOCAL sorted array (fixes duplicates & memory leaks)
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
    // 5. Build the Main Chain
    std::vector<int> chain;
    chain.push_back(sorted_pairs[0].first); // Push the first loser
    for (size_t i = 0; i < sorted_pairs.size(); i++)
        chain.push_back(sorted_pairs[i].second); // Push all winners

    // 6. Insert Losers using Jacobsthal
    std::vector<size_t> order = jacobsthalOrder(sorted_pairs.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        if (idx == 0) continue;

        int loser  = sorted_pairs[idx].first;
        int winner = sorted_pairs[idx].second;

        // Find limit to optimize Binary Search
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
    // 7. Insert Extra if it exists
    if (current_hasExtra)
    {
        size_t pos = std::lower_bound(chain.begin(), chain.end(), current_extra) - chain.begin();
        chain.insert(chain.begin() + pos, current_extra);
    }
    // 8. Assign back to referenced vector
    v = chain;
}
//Deque - private helpers
std::deque<int> PmergeMe::buildchainDeque()
{
    std::deque<int> chain;
    chain.push_back(_sortedPairsDeque[0].first);
    for(size_t i = 0; i < _sortedPairsDeque.size(); i++)
        chain.push_back(_sortedPairsDeque[i].second);
    return chain;
}
void PmergeMe::insertLosersDeque(std::deque<int>& chain)
{
    std::vector<size_t> order = jacobsthalOrder(_sortedPairsDeque.size());
    for (size_t k = 0; k < order.size(); k++)
    {
        size_t idx = order[k];
        if (idx == 0)
            continue;
        
        int loser = _sortedPairsDeque[idx].first;
        int winner = _sortedPairsDeque[idx].second;
        
        size_t limit = chain.size();
        for (size_t p = 0; p < chain.size(); p++)
            if (chain[p] == winner)
            {
                limit = p;
                break;
            }
        size_t pos = std::lower_bound(chain.begin(), chain.begin() + limit, loser) - chain.begin();
        chain.insert(chain.begin() + pos, loser);
    }
}
//deque - recursive sort
void PmergeMe::makePairsDeque(std::deque<int>& d)
{
    // Re-use the shared attributes!
    _pairs.clear();
    _hasExtra = false;
    _extra = 0;
   
    // WARNING: Make absolutely sure this says d.size() and NOT v.size() or _vector.size()
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
    // 1. Populate the shared class attributes
    makePairsDeque(d);
    // 2. SAVE STATE locally before recursion
    std::vector<std::pair<int,int> > current_pairs = _pairs;
    int  current_extra    = _extra;
    bool current_hasExtra = _hasExtra;

    // 3. Extract winners and recurse
    std::deque<int> winners;
    for (size_t i = 0; i < current_pairs.size(); i++)
        winners.push_back(current_pairs[i].second);  
    sortDeque(winners); 

    // 4. Safely align pairs locally
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
    // 5. Build the Main Chain
    std::deque<int> chain;
    chain.push_back(sorted_pairs[0].first);
    for (size_t i = 0; i < sorted_pairs.size(); i++)
        chain.push_back(sorted_pairs[i].second);
    // 6. Insert Losers using Jacobsthal
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
    // 7. Insert Extra if it exists
    if (current_hasExtra)
    {
        size_t pos = std::lower_bound(chain.begin(), chain.end(), current_extra) - chain.begin();
        chain.insert(chain.begin() + pos, current_extra);
    }
    // 8. Assign back to referenced deque
    d = chain;
}

// Calculates time in SECONDS to match the subject's visual typo
static double getTimeSeconds()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec + ts.tv_nsec / 1e9);  // nanoseconds → seconds
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

void PmergeMe::printTime() const
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << _timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque  : " << _timeD << " us" << std::endl;
}
