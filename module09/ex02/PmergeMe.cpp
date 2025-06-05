#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _deque(copy._deque)
{
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
   std::cout << "PmergeMe copy assignment operator called" << std::endl;
   if (this != &copy)
   {
    _vector = copy._vector;
    _deque = copy._deque;
   }
   return *this;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe destructor called" << std::endl;
}

static void sendError()
{
    std::cerr << "Error" << std::endl;
    exit (1);
}

void PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        std::string token;
        while (iss >> token)
        {
            for (size_t j = 0; j < token.size(); j++)
            {
                if (!std::isdigit(token[j]))
                    sendError();
            }
            long num = std::strtol(token.c_str(), NULL, 10);
            if (num < 0 || num > INT_MAX)
                sendError();
           for (size_t k = 0; k < _vector.size(); k++)
            {
                if (_vector[k] == (int)num)
                    sendError();
            }
            _vector.push_back(static_cast<int>(num));
            _deque.push_back(static_cast<int>(num));
        }
    }
}

template <typename Container>
static void fordJohnsonSort(Container &container)
{
    if (container.size() <= 1)
        return;

    Container mainChain;
    Container pend;

    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        int first = *it;
        ++it;
        if (it == container.end())
        {
            pend.push_back(first);
            break;
        }
        int second = *it;
        ++it;

        if (first > second)
            std::swap(first, second);

        pend.push_back(first);
        mainChain.push_back(second);
    }

    fordJohnsonSort(mainChain);

    for (typename Container::iterator pit = pend.begin(); pit != pend.end(); ++pit)
    {
        typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), *pit);
        mainChain.insert(pos, *pit);
    }

    container = mainChain;
}

void PmergeMe::sortAlgo(int argc, char **argv)
{
    parse(argc, argv);

    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    
    std::clock_t startV = std::clock();
    fordJohnsonSort(_vector);
    std::clock_t endV = std::clock();

    std::clock_t startD = std::clock();
    fordJohnsonSort(_deque);
    std::clock_t endD = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    
    double durationV = static_cast<double>(endV - startV) / (CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " 
              << durationV * 1e6 << " µs" << std::endl;
    
    double durationD = static_cast<double>(endD - startD) / (CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " 
              << durationD * 1e6 << " µs" << std::endl;
}
