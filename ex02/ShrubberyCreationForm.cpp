 #include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm:: _fileName = 
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"    //// \\\\-\n";

ShrubberyCreationForm:: ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target_shrubbery("default")
{

}


ShrubberyCreationForm:: ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target_shrubbery(target)
{
}

ShrubberyCreationForm:: ~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm:: ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src.getTarget(), 145, 137)
{
    *this = src.getTarget();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
    {
        this->_target_shrubbery = rhs.getTarget();
    }
    return *this;
}

std:: string ShrubberyCreationForm::getTarget(void) const
{
    return this->_target_shrubbery;
}

void    ShrubberyCreationForm::setTarget(std::string target)
{
    this->_target_shrubbery = target;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(getSigned() == false)
        throw AForm::NotSignedException(); 
    else if (executor.getGrade() <= this->getGrade_exec())
    {
        std::ofstream ofs(this->_target_shrubbery + "_shrubbery");
        ofs << _fileName;
        ofs.close();
    }
    else
        throw AForm::GradeTooLowException();
}
