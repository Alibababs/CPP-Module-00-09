#ifndef  AFORM_HPP
#define  AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
    public:
        AForm();
        AForm(std::string const & name, int const &grade_to_sign, int const &grade_to_execute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        const std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);

        virtual void exec() const = 0;
        virtual std::string getTarget() const = 0;

       void execute(Bureaucrat const & executor) const;

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

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
