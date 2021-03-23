#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class Sed
{

	public:

		Sed();
		~Sed();
		Sed(std::string title);
		
		int			replace(std::string s1, std::string s2);
		void		setInputile(std::string);
		void		setOutputile(std::string);
		void		setSuffix(std::string suffix);

		std::string		getInputFile(void);
		std::string		getOutputFile(void);
		std::ifstream	&getIfs(void);
		std::ofstream	&getOfs(void);
	
	private:
		std::string		_suffix;
		std::string		_inputFile;
		std::string		_outputFile;
		std::ifstream	*_ifs;
		std::ofstream	*_ofs;
		bool			_iState;
		
		bool			checkInValidity();
		bool			checkOutValidity() const;


};

#endif /* ************************************************************* SED_H */