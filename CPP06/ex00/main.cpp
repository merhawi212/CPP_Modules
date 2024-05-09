#include "ScalarConverter.hpp"

// void print(const std::string &literal){
//         // Convert to int
//         int i;
//         std::stringstream intStream(literal);
//         if (intStream >> i) {
//             std::cout << "int: " << i << std::endl;
//         } else {
//             std::cout << "int: impossible" << std::endl;
//         }

//         // Convert to float
//         // float f;
//         // std::stringstream floatStream(literal);
//         const char * str = literal.c_str();
//         double tmp = strtod(str, NULL);
//         if (abs(tmp) <= FLT_MAX) {
//             std::cout << "float: " << std::fixed << std::setprecision(1) << tmp << "f" << std::endl;
//         } else {
//             std::cout << "float: impossible" << std::endl;
//         }

//         double d;
//         std::stringstream doubleStream(literal);
//         if (doubleStream >> d) {
//             std::cout << "double: " <<  d << std::endl;
//         } else if (literal == "nan" || literal == "-inf" || literal == "+inf") {
//             std::cout << "double: " << literal << std::endl;
//         } else {
//             std::cout << "double: impossible" << std::endl;
//         }
// }

int main (int argc, char **argv){

   if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal1>" << std::endl;
        return 1;
    }

    try {
        ScalarConverter::convert(argv[1]);
    }catch(const ScalarConverter::InvalidType & e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}

