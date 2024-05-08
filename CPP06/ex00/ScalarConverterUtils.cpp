//ScalarConverterUtils.cpp
#include "ScalarConverter.hpp"

ScalarConverter::e_types ScalarConverter::literal_type = UNKNOWN_TYPE;
char ScalarConverter::char_type = 'c';
int  ScalarConverter::int_type = 0;
float  ScalarConverter::float_type = 0.0f;
double  ScalarConverter::double_type = 0.0;

int ScalarConverter::isSingleCharOrInt(const std::string &literal){
     if (isprint(literal[0])){
        char_type = literal[0];
        literal_type = CHAR_TYPE;
        return CHAR_TYPE;
     }
     else if (isdigit(literal[0])){
        int_type = atoi(literal.c_str());
        literal_type = INT_TYPE;
        return INT_TYPE;
     }
    return -1;
}

int ScalarConverter::isInt(const std::string &literal){
     if (isalpha(literal[0]))
        return (-1);
    // Convert std::string to const char*
    const char* str = literal.c_str();
    char *endptr;
    double tmp = strtod(str, &endptr);
    // Check if the conversion failed
    if (*endptr != '\0')
        return -1;
    else if (tmp < INT_MIN || tmp > INT_MAX)
        return -1;
    int_type = static_cast<int>(tmp);
    literal_type = INT_TYPE;
    return INT_TYPE; // Conversion successful, number is valid
}

int ScalarConverter::isFloat(const std::string &literal){
    if (isalpha(literal[0]))
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
    float_type = static_cast<int>(tmp);
    literal_type = FLOAT_TYPE;
     // Conversion successful, number is valid
    return FLOAT_TYPE;
}

int ScalarConverter::isDouble(const std::string &literal){
    if (isalpha(literal[0])) //check if the first char is alpha
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
    double_type = static_cast<int>(tmp);
    literal_type = DOUBLE_TYPE;
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