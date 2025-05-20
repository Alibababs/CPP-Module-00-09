#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("notarget")
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
   std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_target = copy._target;
   return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::exec() const
{
    std::cout << "BRRRR... BZZZZ... BRRRR..." << std::endl;
	std::srand(std::time(NULL));
    
    int success = rand() % 2;

    if (success)
        std::cout << getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << getTarget() << " robotomy failed." << std::endl;
}
