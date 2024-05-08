#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(void){
    std::cout << "Default ScalarConverter constructor called."  << std::endl;
}

ScalarConverter::~ScalarConverter(void){
    std::cout << "ScalarConverter destructor called."  << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & src){
    std::cout << "Copy assignment ScalarConverter constructor called."  << std::endl;
    *this = src;
}

ScalarConverter &ScalarConverter::operator =(const ScalarConverter &){
    std::cout << "Copy assignment operator ScalarConverter constructor called."  << std::endl;
    return *this;
}



void fromChar(){
    //  char c;
    // if (isPrintable(literal[0])){
    //     std::cout << "char: |" << literal << "|" << std::endl;
    // }
    // else if ((std::isdigit(literal[0]) && isNumeric(literal[0])))  {
    //         int asciiValue;
    //     std::istringstream(literal) >> asciiValue;
    //     c = static_cast<char>(asciiValue);
    //     std::cout << "char: '" << c << "'" << std::endl;
    // } 
    // else {
    //     std::cout << "char: Non displayable" << std::endl;
    // }
    std::cout << "Char: '" << char_type << "'"<<std::endl;
    std::cout << "Int: " << static_cast<int>(char_type) << std::endl;
    td::cout << "Float: " << static_cast<float>(char_type) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(double_type) << std::endl;
}

void fromInt(){
    
    if (int_type >= 32 && int_type <= 126){
        std::cout << "Char: '" << static_cast<char>(int_type) << "'"<<std::endl;
    }else{
        std::cout << "Char: Non displayable"<<std::endl;
    }
    std::cout << "Int: " << int_type << std::endl;
    std::cout << "Float: " << static_cast<float>(int_type) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(int_type) << std::endl;
}

void fromFloat(){
    
    if (float_type >= 32 && float_type <= 126){
        std::cout << "Char: '" << static_cast<char>(float_type) << "'"<<std::endl;
    }else{
        std::cout << "Char: Non displayable"<<std::endl;
    }
    if (float_type >= INT_MIN && float_type <= INT_MAX){
        std::cout << "Int: " << static_cast<int>(float_type) << std::endl;
    }else{
        std::cout << "Int: Non displayable"<<std::endl;
    }
    std::cout << "Float: " << float_type << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(float_type) << std::endl;
}

void fromDouble(){
     if (double_type >= 32 && double_type <= 126){
        std::cout << "Char: '" << static_cast<char>(double_type) << "'"<<std::endl;
    }else{
        std::cout << "Char: Non displayable"<<std::endl;
    }
    if (double_type >= INT_MIN && double_type <= INT_MAX){
        std::cout << "Int: " << static_cast<int>(double_type) << std::endl;
    }else{
        std::cout << "Int: Non displayable"<<std::endl;
    }
    if (double_type >= FLT_MIN && double_type <= FLT_MAX){
        std::cout << "Float: " << static_cast<float>(double_type) << "f" << std::endl;
    }else{
        std::cout << "Float: Non displayable"<<std::endl;
    }
    std::cout << "Double: " << double_type << std::endl;
}

void  printPseudo(){
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;
    td::cout << "Float: " << float_type << "f" << std::endl;
    std::cout << "Double: " << double_type << std::endl;
    // if (literal == "-inf" || literal == "+inf" || literal == "nan") {
    //     std::cout << "Double: " << literal << std::endl;
    //     std::cout << "Float: " << literal << "f" << std::endl;
    // } else if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
    //     std::string double_t = literal.substr(0, literal.size() - 1); // Exclude last 'f' for double
    //     std::cout << "Double: " << double_t << std::endl;
    //     std::cout << "Float: " << literal << std::endl;
    // }
}


int ScalarConverter::parseInput(const std::string &literal){
   
    if (literal.size() == 1){
        if (isSingleCharOrInt(literal) == INT_TYPE)
           return INT_TYPE;
        else if (isSingleCharOrInt(literal) == CHAR_TYPE)
           return CHAR_TYPE;
        else
            return UNKNOWN_TYPE;
    }
    else if (isPseudo(literal) == PSEUDOS_TYPE)
       return PSEUDOS_TYPE;
    else if (isInt(literal) == INT_TYPE)
       return INT_TYPE;
    else if (isFloat(literal) == FLOAT_TYPE)
       return FLOAT_TYPE;
    else if (isDouble(literal) == DOUBLE_TYPE)
        return DOUBLE_TYPE;
    else 
        return UNKNOWN_TYPE;
}

ScalarConverter::e_types ScalarConverter::getLiteralType() {
    return literal_type;
}

void ScalarConverter::convert(const std::string &literal) {
        parseInput(literal); // Call member function
        switch (getLiteralType()) {
            case CHAR_TYPE:
                 fromChar();
                break;
            case INT_TYPE:
                fromInt();
                break;
            case FLOAT_TYPE:
                fromFloat();
                break;
            case DOUBLE_TYPE:
                fromDouble();
                break;
            case PSEUDOS_TYPE:
                printPseudo();
                break;
            default:
                throw new InvalidType();
        }



 // else if (literal.size() > 1 && std::isdigit(value)) {
        //     int asciiValue;
        //     std::istringstream(literal) >> asciiValue;
        //     c = static_cast<char>(asciiValue);
        //     std::cout << "char: '" << c << "'" << std::endl;
        // } 
        // Convert to int
        int i;
        std::stringstream intStream(literal);
        if (intStream >> i) {
            std::cout << "int: " << i << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }

        // Convert to float
        float f;
        std::stringstream floatStream(literal);
        if (floatStream >> f) {
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } else {
            std::cout << "float: impossible" << std::endl;
        }

        double d;
        std::stringstream doubleStream(literal);
        if (doubleStream >> d) {
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        } else if (literal == "nan" || literal == "-inf" || literal == "+inf") {
            std::cout << "double: " << literal << std::endl;
        } else {
            std::cout << "double: impossible" << std::endl;
        }
    
 }

 
const char *ScalarConverter::InvalidType::what() const throw(){
    return ("Invalid input type! Please provide valid input. Valid inputs are Char, Int, Float, Double and Pseudo.");
 }