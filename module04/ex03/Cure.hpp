#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"

class Cure
{
	protected:
		std::string _type;
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &copy);
		virtual ~Cure();

        Cure(std::string const & type);

	        
		virtual Cure* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif