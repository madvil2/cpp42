#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150), _target("default") {
}


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}


AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute),
      _target(other._target) {
}


AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        
        _signed = other._signed;
        _target = other._target;
    }
    return *this;
}


AForm::~AForm() {
}


std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

std::string AForm::getTarget() const {
    return _target;
}


void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign) {
        _signed = true;
    } else {
        throw GradeTooLowException();
    }
}


void AForm::checkExecuteRequirements(Bureaucrat const & executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
}


const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high! The highest grade is 1.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low or bureaucrat's grade is insufficient!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed and cannot be executed!";
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() 
       << ", Target: " << form.getTarget()
       << ", Sign Status: " << (form.isSigned() ? "Signed" : "Not Signed")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
