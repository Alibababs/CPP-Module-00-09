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
    typedef std::pair<int, int> Pair;

    if (container.size() <= 1) {
        return;
    }

    bool odd = (container.size() % 2 != 0);
    int straggler;
    if (odd) 
    {
        straggler = container.back();
        container.pop_back();
    }

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

    // first element (max) pairs in container
    Container firsts;
    for (size_t i = 0; i < pairs.size(); ++i)
        firsts.push_back(pairs[i].first);

    fordJohnsonSort(firsts);

    // Reconstruction de pend : les seconds éléments des paires dans l'ordre des firsts triés
    Container pend;
    for (typename Container::iterator it = firsts.begin(); it != firsts.end(); ++it) 
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

    // Construction de la chaîne principale (main_chain)
    Container main_chain;
    if (!pend.empty())
        main_chain.push_back(pend[0]);
    for (typename Container::iterator it = firsts.begin(); it != firsts.end(); ++it)
        main_chain.push_back(*it);

    // Calcul de la séquence Jacobsthal pour l'ordre d'insertion
    size_t pend_size = pend.size();
    if (pend_size > 1) 
    {
        std::vector<size_t> jacob;
        jacob.push_back(0);
        jacob.push_back(1);

        // Génération des indices Jacobsthal jusqu'à dépasser pend_size
        while (true) 
        {
            size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
            if (next > pend_size - 1) 
                break;
            jacob.push_back(next);
        }

        // Construction de la séquence d'indices à insérer dans l'ordre correct
        std::vector<size_t> sequence;
        for (size_t i = 1; i < jacob.size(); ++i) 
        {
            size_t start = jacob[i];
            size_t prev = jacob[i - 1];
            // Descendre de start à prev + 1 inclus (descendant)
            for (size_t j = start; j > prev; --j) 
            {
                if (j <= pend_size - 1)
                    sequence.push_back(j);
            }
        }

        // Ajouter le reste des indices non couverts par Jacobsthal en fin, dans l'ordre descendant
        size_t last_jacob = jacob[jacob.size() - 1];
        for (size_t j = pend_size - 1; j > last_jacob; --j)
            sequence.push_back(j);

        // Insertion dans main_chain selon la séquence calculée
        for (size_t i = 0; i < sequence.size(); ++i) 
        {
            int element = pend[sequence[i]];
            typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), element);
            main_chain.insert(pos, element);
        }
    }

    // Insérer le straggler si besoin
    if (odd) 
    {
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    // Remplacer le container original par la chaîne triée
    container = main_chain;
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
              << durationV * 1e3 << " ms" << std::endl;
    
    double durationD = static_cast<double>(endD - startD) / (CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " 
              << durationD * 1e3 << " ms" << std::endl;
}
