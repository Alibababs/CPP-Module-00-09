#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);
        ~PmergeMe();

        void printTime(int argc, char **argv, double durationV, double durationD);
        int sortAlgo(int argc, char **argv);
};

#endif