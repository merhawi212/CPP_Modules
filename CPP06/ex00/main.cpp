#include "ScalarConverter.hpp"
void print(const std::string &literal){
        // Convert to int
        int i;
        std::stringstream intStream(literal);
        if (intStream >> i) {
            std::cout << "int: " << i << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }

        // Convert to float
        // float f;
        // std::stringstream floatStream(literal);
        const char * str = literal.c_str();
        double tmp = strtod(str, NULL);
        if (abs(tmp) <= FLT_MAX) {
            std::cout << "float: " << std::fixed << std::setprecision(1) << tmp << "f" << std::endl;
        } else {
            std::cout << "float: impossible" << std::endl;
        }

        double d;
        std::stringstream doubleStream(literal);
        if (doubleStream >> d) {
            std::cout << "double: " <<  d << std::endl;
        } else if (literal == "nan" || literal == "-inf" || literal == "+inf") {
            std::cout << "double: " << literal << std::endl;
        } else {
            std::cout << "double: impossible" << std::endl;
        }
}
int main (int argc, char **argv){

//    if (argc < 2) {
//         std::cerr << "Usage: " << argv[0] << " <literal1> <literal2> <literal3> ..." << std::endl;
//         return 1;
//     }

    // for (int i = 1; i < argc; ++i) {
    //     std::cout << "Literal: " << argv[i] << std::endl;
    //     ScalarConverter::convert(argv[i]);
    //     std::cout << std::endl;
    // }
    (void)argc;
    // if (isalpha(argv[1][0]))
    //     print(argv[1]);

    std::cout << "Literal: " << argv[1] << std::endl;
    char *endptr;
	double temp = strtod((argv[1]), &endptr);
    float f = strtof((argv[1]), NULL);

    
    std::cout << "flaot |"<< f << "|" << std::endl;
    std::cout << "flaot_d |"<< strtod((argv[1]), NULL) << "|" << std::endl;
    std::cout << "double |"<< temp << "|" << std::endl;
    std::cout << "int |"<< static_cast<int> (temp) << "|" << std::endl;



    std::cout << "endptr |" << endptr << "|" << std::endl;
    
    return 0;
}


// #include <iostream>
// #include <cctype>

// bool isPrintable(char c) {
//     return (c >= 32 && c <= 126);
// }

// int main() {
//     char c = -42; // Example character
//     bool ispri = isPrintable(c);
//     std::cout << ispri << std::endl;
//     if (isPrintable(c)) {
//         std::cout << c << " is a printable character." << std::endl;
//     } else {
//         std::cout << c << " is not a printable character." << std::endl;
//     }
//     return 0;
// }
