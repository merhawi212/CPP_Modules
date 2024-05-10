#include "ScalarConverter.hpp"

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
	catch(const std::exception & e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}

