#include "AForm.hpp"

AForm::AForm() : _name("noname"),
			   _signed(false), 
			   _grade_to_sign(150), 
			   _grade_to_execute(150)
{
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string const & name, int const &grade_to_sign, int const &grade_to_execute) : _name(name), 
																							  _signed(false), 
																							  _grade_to_sign(grade_to_sign), 
																							  _grade_to_execute(grade_to_execute)
{
	std::cout << "AForm name constructor called" << std::endl;
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw GradeTooLowException();
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &copy) : _name(copy._name),
							   _signed(copy._signed),
							   _grade_to_sign(copy._grade_to_sign), 
							   _grade_to_execute(copy._grade_to_execute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
   std::cout << "AForm copy assignment operator called" << std::endl;
   if (this != &copy)
   	this->_signed = copy._signed;

   return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ":" << std::endl
	   << "Signed: " << f.getSigned() << std::endl
	   << "Grade to sign: " << f.getGradeToSign() << std::endl
	   << "Grade to execute: " << f.getGradeToExecute();
	return os;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_to_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw FormNotSigned();
	if (executor.getGrade() > _grade_to_execute)
		throw GradeTooLowException();
	exec();
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "The form is not signed!";
}


