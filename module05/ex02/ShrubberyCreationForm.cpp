#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("notarget")
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
   std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
   if (this != &copy)
        this->_target = copy._target;
   return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::exec() const
{
    std::string file_name = _target + "_shrubbery";
    std::ofstream file(file_name.c_str());
    if (!file)
    {
        std::cout << "Failed to create outfile." << std::endl;
        return ;
    }
    file <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";
	file.close();
}
