#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class IMateriaSource
{
  private:
      std::string _type;
      AMateria *_inventory[4];
  public:
      IMateriaSource();
      IMateriaSource(const IMateriaSource &copy);
      IMateriaSource &operator=(const IMateriaSource &copy);

      IMateriaSource(std::string const & type);

      virtual ~IMateriaSource() {}
      virtual void learnMateria(AMateria*) = 0;
      virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif