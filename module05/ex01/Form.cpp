#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}


Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}


Form& Form::operator=(const Form& other) {
    if (this != &other) {
        
        _signed = other._signed;
    }
    return *this;
}


Form::~Form() {
}


std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}


void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign) {
        _signed = true;
    } else {
        throw GradeTooLowException();
    }
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! The highest grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! The lowest grade is 150.";
}


std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << ", Sign Status: " << (form.isSigned() ? "Signed" : "Not Signed")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
