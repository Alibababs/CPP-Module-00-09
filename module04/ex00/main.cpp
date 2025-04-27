#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();
    std::cout << wronganimal->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;
    wrongcat->makeSound(); //will output the animal sound!
    wronganimal->makeSound();

    delete wronganimal;
    delete wrongcat;

    return 0;
}
