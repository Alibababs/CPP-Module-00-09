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

static int isvalidArgument(int argc, char **argv)
{
    std::vector<int> temp_vector;

    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        std::string token;
        while (iss >> token)
        {
            for (size_t j = 0; j < token.size(); j++)
                if (!std::isdigit(token[j]))
                    return (1);
            long num = std::strtol(token.c_str(), NULL, 10);
            if (num < 0 || num > INT_MAX)
                return (1);
            for (size_t k = 0; k < temp_vector.size(); k++)
                if (temp_vector[k] == (int)num)
                    return (1);
            temp_vector.push_back(static_cast<int>(num));
        }
    }
    return 0;
}


template <typename Container>
static void fordJohnsonSort(Container &container) 
{
    typedef std::pair<int, int> Pair;

    if (container.size() <= 1)
        return;

    // Gestion de l'element impair
    bool odd = (container.size() % 2 != 0);
    int straggler = 0;
    if (odd) 
    {
        straggler = container.back();
        container.pop_back();
    }

    // Creation des paires
    std::vector<Pair> pairs;
    for (size_t i = 0; i < container.size(); i += 2) 
    {
        int a = container[i];
        int b = container[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    // Premier element (max) dans firsts, second dans pend
    Container firsts;
    for (size_t i = 0; i < pairs.size(); i++)
        firsts.push_back(pairs[i].first);

    fordJohnsonSort(firsts);

    // Reconstruction de pend : les seconds elements des paires dans l'ordre des firsts tries
    Container pend;
    for (typename Container::iterator it = firsts.begin(); it != firsts.end(); it++) 
    {
        int first_val = *it;
        for (typename std::vector<Pair>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) 
        {
            if (pit->first == first_val) 
            {
                pend.push_back(pit->second);
                pairs.erase(pit);
                break;
            }
        }
    }

    // Construction de la main_chain
    Container main_chain;
    if (!pend.empty())
        main_chain.push_back(pend[0]);
    for (typename Container::iterator it = firsts.begin(); it != firsts.end(); it++)
        main_chain.push_back(*it);

    // Calcul de la sequence Jacobsthal
    size_t pend_size = pend.size();
    if (pend_size > 1) 
    {
        std::vector<size_t> jacob;
        jacob.push_back(0);
        jacob.push_back(1);

        while (1) 
        {
            size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
            if (next > pend_size - 1) 
                break;
            jacob.push_back(next);
        }

        // Construction de la sequence d'insertion
        std::vector<size_t> sequence;
        for (size_t i = 1; i < jacob.size(); i++) 
        {
            size_t start = jacob[i];
            size_t prev = jacob[i - 1];
            // Insertion selon la sequence
            for (size_t j = start; j > prev; --j) 
            {
                if (j <= pend_size - 1)
                    sequence.push_back(j);
            }
        }

        // Ajouter le reste non couverts par Jacobsthal en fin
        size_t last_jacob = jacob[jacob.size() - 1];
        for (size_t j = pend_size - 1; j > last_jacob; j--)
            sequence.push_back(j);

        // Insertion dans main_chain selon la sequence calculee
        for (size_t i = 0; i < sequence.size(); i++) 
        {
            typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[sequence[i]]);
            main_chain.insert(pos, pend[sequence[i]]);
        }
    }

    // Insertion de l'element impair
    if (odd) 
    {
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    container = main_chain;
}

int PmergeMe::sortAlgo(int argc, char **argv)
{
    if (isvalidArgument(argc, argv) == 1)
        return (1);

    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    
    std::clock_t startV = std::clock();
    for (int i = 1; i < argc; i++)
        _vector.push_back(std::atoi(argv[i]));
    fordJohnsonSort(_vector);
    std::clock_t endV = std::clock();

    std::clock_t startD = std::clock();
    for (int i = 1; i < argc; i++)
        _deque.push_back(std::atoi(argv[i]));
    fordJohnsonSort(_deque);
    std::clock_t endD = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    
    double durationV = static_cast<double>(endV - startV) / (CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << _vector.size() 
              << " pend[sequence[i]]s with std::vector : " 
              << durationV * 1e3 << " ms" << std::endl;
    
    double durationD = static_cast<double>(endD - startD) / (CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << _deque.size() 
              << " pend[sequence[i]]s with std::deque  : " 
              << durationD * 1e3 << " ms" << std::endl;
    return 0;
}
