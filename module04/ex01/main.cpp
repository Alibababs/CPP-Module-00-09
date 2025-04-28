#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "========= TEST SUBJECT =========" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "========= INIT ANIMAL =========" << std::endl;

    Animal *list[6];

    for (int i = 0; i < 6; i++)
    {
        if (i < 3)
            list[i] = new Dog();
        else
            list[i] = new Cat();
    }

    std::cout << "========= CHECK TYPE =========" << std::endl;
    
    std::cout << list[2]->getType() << std::endl;
    std::cout << list[3]->getType() << std::endl;

    std::cout << "========= CHECK DEEP COPY =========" << std::endl;

    Dog *dogA = new Dog;
    Dog *dogB = new Dog(*dogA);
    
    std::cout << "Address of DogA brain: " << dogA->getBrainAddress() << std::endl;
    std::cout << "Address of DogB brain: " << dogB->getBrainAddress() << std::endl;\
    
    dogA->setIdea(0, "First idea");
    dogB->setIdea(1, "Second idea");

    std::cout << "DogA idea index 0: " << dogA->getIdea(0) << std::endl;
    std::cout << "DogB idea index 1: " << dogB->getIdea(1) << std::endl;

    delete dogA;
    delete dogB;

    std::cout << "===========================" << std::endl;

    Dog *catA = new Dog;
    Dog *catB = new Dog;
    *catA = *catB;

    std::cout << "Address of DogA brain: " << catA->getBrainAddress() << std::endl;
    std::cout << "Address of DogB brain: " << catB->getBrainAddress() << std::endl;

    catA->setIdea(0, "First idea");
    catB->setIdea(1, "Second idea");

    std::cout << "DogA idea index 0: " << catA->getIdea(0) << std::endl;
    std::cout << "DogB idea index 1: " << catB->getIdea(1) << std::endl;

    delete catA;
    delete catB;

    std::cout << "========= DELETE =========" << std::endl;

    for (int i = 0; i < 6; i++)
        delete list[i];

    return 0;
}
