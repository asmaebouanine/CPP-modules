/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:41:46 by asbouani          #+#    #+#             */
/*   Updated: 2026/02/28 20:13:23 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _gradeSign(150), _gradeExec(150), _signed(false) {}

AForm::AForm(const std::string& name, const int gradeSign, const int gradeExec) : _name(name),
             _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed){}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}
std::string AForm::getName() const
{
    return (_name);
}
int AForm::getGradeSign() const
{
    return (_gradeSign);
}
int AForm::getGradeExec() const
{
    return (_gradeExec);
}
bool AForm::getSigned() const
{
    return (_signed);
}
void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > getGradeSign())
        throw GradeTooLowException();
    _signed = true;    
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw AForm::GradeTooLowException();
    executeAction();
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high.");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low.");
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed.");
}
std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.getName() << " Grade to Sign " << f.getGradeSign() << " Grade to Execute "
    << f.getGradeExec() << " signed " << f.getSigned() << ".";
    return (out);
}
AForm::~AForm() {}