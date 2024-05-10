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


void ScalarConverter::fromChar(){
    int_type = static_cast<int>(char_type);
    float_type = static_cast<float>(char_type);
    double_type = static_cast<double>(char_type);

    std::cout << "Char: '" << char_type << "'"<<std::endl;
    std::cout << "Int: " << int_type << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(2) << float_type << "f" << std::endl;
    std::cout << "Double: " << double_type << std::endl;
}

void ScalarConverter::fromInt(){
    
    if (int_type >= 32 && int_type <= 126){
        char_type = static_cast<char>(int_type);
        std::cout << "Char: '" << char_type << "'"<<std::endl;
    }else
        std::cout << "Char: Non displayable"<<std::endl;
    std::cout << "Int: " << int_type << std::endl;
    float_type = static_cast<float>(int_type);
    double_type = static_cast<double>(int_type);
    std::cout << "Float: " << std::fixed << std::setprecision(2) << float_type << "f" << std::endl;
    std::cout << "Double: " << double_type << std::endl;
}

void ScalarConverter::fromFloat(){
    if (float_type >= 32 && float_type <= 126){
        char_type = static_cast<char>(float_type);
        std::cout << "Char: '" << char_type << "'"<<std::endl;
    }else
        std::cout << "Char: Non displayable"<<std::endl;
    if (float_type >= INT_MIN && float_type <= INT_MAX){
        int_type = static_cast<int>(float_type);
        std::cout << "Int: " << int_type << std::endl;
    }else
        std::cout << "Int: Non displayable"<<std::endl;
    double_type = static_cast<double>(float_type);
    std::cout << "Float: " << std::fixed << std::setprecision(2)  << float_type << "f" << std::endl;
    std::cout << "Double: " << double_type << std::endl;
}

void ScalarConverter::fromDouble(){
     if (double_type >= 32 && double_type <= 126){
         char_type = static_cast<char>(double_type);
        std::cout << "Char: '" << char_type << "'"<<std::endl;
    }else{
        std::cout << "Char: Non displayable"<<std::endl;
    }
    if (double_type >= INT_MIN && double_type <= INT_MAX){
        int_type = static_cast<int>(double_type);
        std::cout << "Int: " << int_type << std::endl;
    }else{
        std::cout << "Int: Non displayable"<<std::endl;
    }
    if (abs(double_type) <= FLT_MAX){
        float_type = static_cast<float>(double_type);
        std::cout << "Float: " << std::fixed << std::setprecision(2)<< float_type << "f" << std::endl;
    }else{
        std::cout << "Float: Non displayable"<<std::endl;
    }
    std::cout << "Double: " << double_type << std::endl;
}

void  ScalarConverter::fromPseudo(){
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;
    std::cout << "Float: " << float_type << "f" << std::endl;
    std::cout << "Double: " << double_type << std::endl;
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
        parseInput(literal); // Call member function to parse the literal
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
                fromPseudo();
                break;
            default:
                throw ScalarConverter::InvalidType();
        }
    
 }

 
const char* ScalarConverter::InvalidType::what() const throw(){
    return ("Invalid input! Please provide valid input. Valid inputs are Char, Int, Float, Double and Pseudo in their ranges, overflow is also consider as invalid.");
 }