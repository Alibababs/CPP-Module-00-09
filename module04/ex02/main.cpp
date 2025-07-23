#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Dog chien;
    Cat chat;

    chien.makeSound();
    chat.makeSound();

    Animal *dog = new Dog();
    Animal *cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    // CAN'T WORK :

    // Animal animal;
    // animal.makeSoud();

    // Animal *a = new Animal();
    // a->makeSound();

    chat.setIdea(0, "TEST");
    Cat chat2 = chat;

    // std::cout << chat.getBrainAddress() << " " << chat2.getBrainAddress();

    chat2.setIdea(0, "COUCOU");
    std::cout << chat.getIdea(0) << " " << chat2.getIdea(0) << std::endl;

    return 0;
}
