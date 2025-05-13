#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();
        
        virtual void makeSound() const;
        void *getBrainAddress() const;
        void setIdea(int const &index, std::string const &idea);
        std::string const &getIdea(int const &index) const;
};

#endif