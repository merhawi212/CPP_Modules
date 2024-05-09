#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <limits>
#include <float.h>
#include <cstdlib>

        
class ScalarConverter {
    private:
        
         enum e_types {
            UNKNOWN_TYPE = -1,
            CHAR_TYPE = 0,
            INT_TYPE,
            FLOAT_TYPE,
            DOUBLE_TYPE,
            PSEUDOS_TYPE
        };
    
        static e_types literal_type; 

        static char char_type;
        static int int_type;
        static float float_type;
        static double double_type;



        static int parseInput(const std::string &literal); // string parser
        static e_types getLiteralType();

        // type checkers
        static int isSingleCharOrInt(const std::string &literal);
        static int isInt(const std::string &literal);
        static int isFloat(const std::string &literal);
        static int isDouble(const std::string &literal);
        static int isPseudo(const std::string &literal);

        // print
        static void fromChar();
        static void fromInt();
        static void fromFloat();
        static void fromDouble();
        static void fromPseudo();


        ScalarConverter(void);  //orthodox cannonical form
		ScalarConverter(const ScalarConverter& src);
        ScalarConverter &operator =(const ScalarConverter& );

    public:
        //orthodox cannonical form
        ~ScalarConverter();
      
        class InvalidType : public std::exception {
				public:
					virtual const char* what() const throw();
		};

        // method
       static void convert(const std::string& literal);

};
#endif //SCALARCONVERTER_HPP