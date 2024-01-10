#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void Harl::debug(){
  std::cout << "[ DEBUG ]\nEverything is fine. Just checking.\n"
  << std::endl;

}

void Harl::info(){
    std::cout << "[ INFO ]\nEverything is proceeding as expected.\n"
        << std::endl;

}
void Harl::warning(){
   
   std::cout << "[ WARNING ] \nSomething might be going wrong.\n" 
        << std::endl;

}

void Harl::error(){
    std::cout << "[ ERROR ]\nOh no! Something went terribly wrong!\n" << std::endl;
}



void Harl::complain(std::string level){
    int levelIndex = -1;
  
    size_t arraySize = getLevelFunctionsSize();

    for (size_t i = 0; i < arraySize; ++i){
        if (level == levelFunctions[i].level) {
            levelIndex = (int)(i);
            break;
        }
    }

    switch(levelIndex){
        case 0:
            debug();
        // Fall through
        case 1:
            info();
            // Fall through
        case 2:
            warning();
            // Fall through
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
            break;
    }
}


const Harl::LevelFunctionPair Harl::levelFunctions[] = {
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}
};

size_t Harl::getLevelFunctionsSize() {
    return sizeof(levelFunctions) / sizeof(levelFunctions[0]);
} 