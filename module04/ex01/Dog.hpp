#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        virtual ~Dog();

        void makeSound() const;
        void *getBrainAddress() const;
        void setIdea(int const &index, std::string const &idea);
        std::string const &getIdea(int const &index) const;
};
