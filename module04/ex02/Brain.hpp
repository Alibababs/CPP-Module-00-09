#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    protected:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        virtual ~Brain();

        void setIdea(int const &index, std::string const &idea);
        std::string const &getIdea(int const &index) const;
};

#endif