#include "Span.hpp"

Span::Span() : _N(0)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span N constructor called" << std::endl;
}

Span::Span(const Span &copy) : _N(copy._N), _v(copy._v)
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
   std::cout << "Span copy assignment operator called" << std::endl;
   if (this != &copy)
   {
       _N = copy._N;
       _v = copy._v;
   }
   return *this;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number)
{
    if (_v.size() >= _N)
        throw std::length_error("Span is full.");
    _v.push_back(number);
}

int Span::shortestSpan() const
{
    if (_v.size() < 2)
        throw std::length_error("Not enough numbers");

    std::vector<int> temp = _v;
    std::sort(temp.begin(), temp.end());

    int result = temp[1] - temp[0];
    for (unsigned int i = 2; i < temp.size(); i++)
    {
        int diff = temp[i] - temp[i - 1];
        if (diff < result)
            result = diff;
    }
    return result;
}

int Span::longestSpan() const
{
    if (_v.size() < 2)
        throw std::length_error("Not enough numbers");

    int min = *std::min_element(_v.begin(), _v.end());
    int max = *std::max_element(_v.begin(), _v.end());

    return max - min;
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (_v.size() + std::distance(begin, end) > _N)
		throw std::length_error("Too much range");
	_v.insert(_v.end(), begin, end);
}