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

    return 0;
}
