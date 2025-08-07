#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <set>
#include <ctime>

#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        
        int parse(int argc, char **argv);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        ~PmergeMe();

        int sortAlgo(int argc, char **argv);
};

#endif