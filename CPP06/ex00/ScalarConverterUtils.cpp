//ScalarConverterUtils.cpp
#include "ScalarConverter.hpp"

ScalarConverter::e_types ScalarConverter::literal_type = UNKNOWN_TYPE;
char ScalarConverter::char_type = 'c';
int  ScalarConverter::int_type = 0;
float  ScalarConverter::float_type = 0.0f;
double  ScalarConverter::double_type = 0.0;


int ScalarConverter::isSingleCharOrInt(const std::string &literal){
    if (isdigit(literal[0])){
        int_type = atoi(literal.c_str());
        literal_type = INT_TYPE;
        return INT_TYPE;
     }
     else if (isprint(literal[0])){
        char_type = literal[0];
        literal_type = CHAR_TYPE;
        return CHAR_TYPE;
     }
    return -1;
}

int ScalarConverter::isInt(const std::string &literal){
     if (isalpha(literal[0]) || literal.find('.') != std::string::npos)
        return (-1);
    // Convert std::string to const char*
    const char* str = literal.c_str();
    char *endptr;
    double tmp = strtod(str, &endptr);
    // Check if the conversion failed
    if (*endptr != '\0' || tmp < INT_MIN || tmp > INT_MAX)
        return -1;
    // Conversion successful, number is valid
    int_type = static_cast<int>(tmp);
    literal_type = INT_TYPE;
    std::cout << "int is: |" << int_type << "| literal: " << literal << std::endl;
    return INT_TYPE; 
}

int ScalarConverter::isFloat(const std::string &literal){
    if (isalpha(literal[0]) || literal.find('.') == std::string::npos)
        return (-1);
    // Check if the string ends with 'f' but not more than once
    int length = literal.length();
    if (length <= 0 && literal[length - 1] != 'f') {
        return -1;
    }
    // Convert std::string to const char*
    const char* str = literal.c_str();

    double tmp = strtod(str, NULL);
    if (tmp < FLT_MIN || tmp > FLT_MAX) // check if its outside the float range
        return -1;

    int countF = 0;
    for (int i = 0; i < length; ++i) {
        if (literal[i] == 'f')
            countF++;
    }
    if (countF != 1)
        return -1; // More or less than one 'f'

         // Conversion successful, number is valid
    float_type = static_cast<float>(tmp);
    literal_type = FLOAT_TYPE;
     std::cout << "float is: |" << float_type << "| literal: " << literal << std::endl;
    return FLOAT_TYPE;
}

int ScalarConverter::isDouble(const std::string &literal){
    //check if the first char is alpha or it has .
    if (isalpha(literal[0]) || literal.find('.') == std::string::npos) 
        return (-1);
    
    // Convert std::string to const char*
    const char* str = literal.c_str();

    char *endptr;
    double tmp = strtod(str, &endptr);
    // Check if the conversion failed
    if (*endptr != '\0') 
        return -1;
    if (tmp < DBL_MIN || tmp > DBL_MAX) // check if its outside the double range
        return -1;
     // Conversion successful, number is valid
    double_type = static_cast<double>(tmp);
    literal_type = DOUBLE_TYPE;
     std::cout << "double is: |" << double_type << "| literal: " << literal << std::endl;
    return DOUBLE_TYPE;
}

int ScalarConverter::isPseudo(const std::string &literal){
    const char *pseudos[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
    for (int i= 0; i < 6;  i++) {
        if (literal == pseudos[i]) {
            float_type = strtod(pseudos[i], NULL);
            double_type = strtod(pseudos[i], NULL);
            literal_type = PSEUDOS_TYPE;
            return PSEUDOS_TYPE;
        }
    }
    return -1;
}