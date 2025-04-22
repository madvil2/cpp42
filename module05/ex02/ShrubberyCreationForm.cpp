#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "default") {
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    
    checkExecuteRequirements(executor);
    
    
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        throw FileOpenException();
    }
    
    
    outfile << "       _-_       " << std::endl;
    outfile << "    /~~   ~~\\    " << std::endl;
    outfile << " /~~         ~~\\ " << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  / " << std::endl;
    outfile << "   ~  \\\\ //  ~   " << std::endl;
    outfile << "_- -   | | _- _  " << std::endl;
    outfile << "  _ -  | |   -_  " << std::endl;
    outfile << "      // \\\\      " << std::endl;
    outfile << std::endl;
    outfile << "        ###        " << std::endl;
    outfile << "       #o###       " << std::endl;
    outfile << "     #####o###     " << std::endl;
    outfile << "    #o#\\#|#/###    " << std::endl;
    outfile << "     ###\\|/#o#     " << std::endl;
    outfile << "      # }|{  #     " << std::endl;
    outfile << "        }|{        " << std::endl;
    
    outfile.close();
}


const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Could not open file for writing!";
}
