#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        ~Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);

        void makeSound() const;

        std::string getType() const;
};

#endif