#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- STATICS --------------------------------
*/

const uint			ShrubberyCreationForm::treeByRow = 3;
const uint			ShrubberyCreationForm::rowByTree = 12;
const std::string	ShrubberyCreationForm::tree[] = {
	"              v .   ._, |_  .,       ",
	"           `-._\\/  .  \\ /    |/_   ",
	"               \\  _\\, y | \\//     ",
	"         _\\_.___\\, \\/ -.\\||      ",
	"           `7-,--.`._||  / / ,       ",
	"           /'     `-. `./ / |/_.'    ",
	"                     |    |//        ",
	"                     |_    /         ",
	"                     |-   |          ",
	"                     |   =|          ",
	"                     |    |          ",
	"--------------------/ ,  . \\------._"
};



/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() :  Form("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	// std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src)
{
	// std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		Form::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				ShrubberyCreationForm::execute(Bureaucrat const & B) const
	throw (Form::gradeTooLowException, Form::formNotSigned)
{
	std::ofstream file(this->_target + "_shrubbery");

	this->checkAllowance(B);
	if (!file.is_open())
		throw ShrubberyCreationForm::fileNotOpened();
	for (uint r = 0; r < 3; r++)
	{
		for (uint i = 0; i < ShrubberyCreationForm::rowByTree; i++)
		{
			for (uint t = 0; t < ShrubberyCreationForm::treeByRow; t++)
			{
				file << ShrubberyCreationForm::tree[i];
			}
			file << std::endl;
		}
	}
	file.flush();
	file.close();
}

Form*			ShrubberyCreationForm::create(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */