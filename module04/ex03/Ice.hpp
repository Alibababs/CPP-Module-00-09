#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"

class Ice
{
	protected:
		std::string _type;
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &copy);
		virtual ~Ice();

        Ice(std::string const & type);
	        
		virtual Ice* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif