#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void Harl::debug(){
  std::cout << "Debug: Everything is fine. Just checking."
  << std::endl;

}

void Harl::info(){
    std::cout << "Info: Everything is proceeding as expected."
        << std::endl;

}
void Harl::warning(){
   
   std::cout << "Warning: Something might be going wrong." 
        << std::endl;

}

void Harl::error(){
    std::cout << "Error: Oh no! Something went terribly wrong!" << std::endl;
}



void Harl::complain(std::string level){
  

    for (int i=0;levelFunctions[i].level != NULL; ++i){
        if (level == levelFunctions[i].level) {
                (this->*levelFunctions[i].function)();
                return;
            }
    }
     std::cout << "Unknown level: " << level << std::endl;

}


const Harl::LevelFunctionPair Harl::levelFunctions[] = {
    {"debug", &Harl::debug},
    {"info", &Harl::info},
    {"warning", &Harl::warning},
    {"error", &Harl::error},
    {NULL, NULL}  // Sentinel to mark the end of the array
};
    