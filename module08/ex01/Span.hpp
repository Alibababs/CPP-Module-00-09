#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
#include <limits>

class Span
{
    private:
        unsigned int _N;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

        void addNumber(int number);
		void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

		int shortestSpan() const; 
		int longestSpan() const;
};

#endif