#include "FileManager.h"
#include <sstream>

// This function reads the file and calls the necessary classes to perform their duties.
void FileManager::readFile(std::string fileName){
    ARMInstruct instruct; // Create an instance of the ARMInstruct class. It is outside the while loop so that the register values are not reset.
    std::ifstream file;
    file.open(fileName);
    std::string line;
    
    if(file.is_open()){ // If the file is open, then read the file.
        while(std::getline(file, line)){
            std::istringstream ss(line);
            ss >> opcode >> rd >> rn >> rm; // The appropriate variables are assigned to the appropriate values.

            if(upper(opcode) == "MOV"){ // checks the opcode and calls the appropriate instruction to perform the instruction.
                std::cout << opcode << " " << rd << " " << rn << std::endl;
                numb = std::stoul(rn.substr(3, rn.length()), nullptr, 16); // used to convert the string hex value to an integer which is currently stores in rn.
                instruct.movInstruct(lower(rd.substr(0,2)), numb);
                instruct.getResult();
            }else if(upper(opcode) == "ADD"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                instruct.addInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), lower(rm.substr(0,2)));
                instruct.getResult();
            }else if(upper(opcode) == "SUB"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                instruct.subInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), lower(rm.substr(0,2)));
                instruct.getResult();
            }else if(upper(opcode) == "AND"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                instruct.andInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), lower(rm.substr(0,2)));
                instruct.getResult();
            }else if(upper(opcode) == "ORR"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                instruct.orrInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), lower(rm.substr(0,2)));
                instruct.getResult();
            }else if(upper(opcode) == "XOR"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                instruct.xorInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), lower(rm.substr(0,2)));
                instruct.getResult();
            }else if(upper(opcode) == "ASR"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                numb = std::stoul(rm.substr(1, rm.length()), nullptr, 16); // used to convert the string hex value to an integer which is currently stores in rm.
                instruct.asrInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), numb);
                instruct.getResult();
            }else if(upper(opcode) == "LSR"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                numb = std::stoul(rm.substr(1, rm.length()), nullptr, 16);// used to convert the string hex value to an integer which is currently stores in rm.
                instruct.lsrInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), numb);
                instruct.getResult();
            }else if(upper(opcode) == "LSL"){
                std::cout << opcode << " " << rd << " " << rn << " " << rm << std::endl;
                numb = std::stoul(rm.substr(1, rm.length()), nullptr, 16); // used to convert the string hex value to an integer which is currently stores in rm.
                instruct.lslInstruct(lower(rd.substr(0,2)), lower(rn.substr(0,2)), numb);
                instruct.getResult();
            }
        }
    }
    file.close(); // close the file.
}

// This function converts the string to uppercase. Used to uppercase the opcode for comparison.
std::string FileManager::upper(std::string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

// This function converts the string to lowercase. Used to lowercase the register names for comparison.
std::string FileManager::lower(std::string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}