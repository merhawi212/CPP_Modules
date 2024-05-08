le#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>  // need to check if its allowed
#include <cstdlib>
#include <limits.h>
#include <float.h>


        
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
    
        static e_types literal_type; // Initialize to UNKNOWN

        static char char_type = 'c';
        static int int_type = 0;
        static float float_type = 0.0f;
        static double double_type = 0.0;



        static int parseInput(const std::string &literal); // string parser
        static e_types getLiteralType();

        // type checkers
        static int isSingleCharOrInt(const std::string &literal);
        static int isInt(const std::string &literal);
        static int isFloat(const std::string &literal);
        static int isDouble(const std::string &literal);
        static int isPseudo(const std::string &literal);

        ScalarConverter(void);  //orthodox cannonical form

    public:
        //orthodox cannonical form
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter &operator =(const ScalarConverter& );

        class InvalidType : public std::exception {
				public:
					virtual const char* what() const throw();
		};

        // method
       static void convert(const std::string& literal);

};
#endif //SCALARCONVERTER_HPP