#ifndef  ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>
 
class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name, int N);
};

#endif