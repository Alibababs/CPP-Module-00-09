#include "Form.hpp"

Form::Form() : _name("noname"),
			   _signed(false), 
			   _grade_to_sign(150), 
			   _grade_to_execute(150)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string const & name, int const &grade_to_sign, int const &grade_to_execute) : _name(name), 
																							  _signed(false), 
																							  _grade_to_sign(grade_to_sign), 
																							  _grade_to_execute(grade_to_execute)
{
	std::cout << "Form name constructor called" << std::endl;
    if (_grade_to_sign > 150 || _grade_to_execute > 150)
        throw GradeTooLowException();
    if (_grade_to_sign < 1 || _grade_to_execute < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &copy) : _name(copy._name),
							   _signed(copy._signed),
							   _grade_to_sign(copy._grade_to_sign), 
							   _grade_to_execute(copy._grade_to_execute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
   std::cout << "Form copy assignment operator called" << std::endl;
   if (this != &copy)
   	this->_signed = copy._signed;

   return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << " form :" << std::endl
	   << "Signed : " << f.getSigned() << std::endl
	   << "Grade to sign : " << f.getGradeToSign() << std::endl
	   << "Grade to execute : " << f.getGradeToExecute();
	return os;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_to_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}
