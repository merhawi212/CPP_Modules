#include <iostream>
#include <fstream>
#include <string>

bool openInFile(std::string filename, std::ifstream& inputFile){
    const char* filenameCStr = filename.c_str();
    inputFile(filenameCStr);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }
   return true;
}

bool openOutFile(std::string filename, std::ofstream& outputFile){
     std::string outputFilename = filename + ".replace";
    const char* outputFilenameCStr = outputFilename.c_str();
      outputFile.open(outputFilenameCStr);
    if (!outputFile.is_open()){
        std::cerr << "Error: Unable to open output file " << outputFilename << std::endl;
    
        return false;
    }
   return true;
}

void processLine(std::string line, std::string& s1, std::string& s2, std::ofstream& outputFile){
    std::string modifiedLine;
    for (size_t i = 0; i < line.length(); ++i) {
        if (line.substr(i, s1.length()) == s1) {
            modifiedLine += s2;
            i += s1.length() - 1; 
        } else {
            modifiedLine += line[i];
        }
    }
    outputFile << modifiedLine << '\n';
}

void replaceInFile(std::string filename, std::string s1, std::string s2){
    std::ifstream inputFile;
    if (!openInFile(filename, inputFile)) {
        return;
    }

    std::ofstream outputFile;
    if (!openOutFile(filename, outputFile)){
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)){
        processLine(line, s1, s2, outputFile);
    }
   
    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]){
   if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceInFile(filename, s1, s2);

    return 0;

}