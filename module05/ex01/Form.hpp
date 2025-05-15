#ifndef  FORM_HPP
#define  FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
    public:
        Form();
        Form(std::string const & name, int const &grade_to_sign, int const &grade_to_execute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        const std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

		void beSigned(Bureaucrat b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
