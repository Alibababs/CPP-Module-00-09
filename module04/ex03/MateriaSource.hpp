#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
      std::string _type;
      AMateria *_inventory[4];
  public:
      MateriaSource();
      MateriaSource(const MateriaSource &copy);
      MateriaSource &operator=(const MateriaSource &copy);
      ~MateriaSource();

      MateriaSource(std::string const & type);
      void learnMateria(AMateria*);
      AMateria* createMateria(std::string const & type);
};

#endif