#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
		std::string _type;
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &copy);
		virtual ~Ice();
	        
		virtual AMateria* clone() const = 0;
		void use(ICharacter& target);
};

#endif