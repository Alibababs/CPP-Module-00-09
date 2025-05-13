#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
      AMateria *_inventory[4];
  public:
      MateriaSource();
      MateriaSource(const MateriaSource &copy);
      MateriaSource &operator=(const MateriaSource &copy);
      ~MateriaSource();

      virtual void learnMateria(AMateria*);
      virtual AMateria* createMateria(std::string const & type);
};

#endif