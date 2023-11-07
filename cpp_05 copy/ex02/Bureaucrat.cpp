#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"


Bureaucrat:: Bureaucrat(): _name("<unnammed>"), _grade(150)
{
    std::cout<<"default constructor called" << std::endl;
}

Bureaucrat:: Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException(grade);
    else if(grade > 150)
        throw GradeTooLowException(grade);
}

Bureaucrat:: Bureaucrat(Bureaucrat const & src)
{
    std::cout<<"copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& rhs)
{
    std::cout<<"Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat:: ~Bureaucrat()
{
    
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::setName(std::string name)
{
    this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

std::ostream& operator<< (std:: ostream & o, Bureaucrat const& rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return o;
}

	//increment grade
void Bureaucrat::incrementGrade(void)
{
    if(this->_grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

//decrement grade
void Bureaucrat::decrementGrade(void)
{
    if(this->_grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}