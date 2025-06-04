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
        
        void parse(int argc, char **argv);
        void sortVector();
        void sortDeque();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        ~PmergeMe();

        void sortAlgo(int argc, char **argv);
};

#endif