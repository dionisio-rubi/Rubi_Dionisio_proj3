#include <string>
#include <iostream>
#include <fstream>

#include "ARMInstruct.h"

class FileManager {
    private:
        std::string rd; // stores rd
        std::string rn; // stores rn
        std::string rm; // stores rm
        uint32_t numb; // stores the number if applicable
        std::string opcode; // The keyword that is used to determine what instruction to perform.
    public:
        void readFile(std::string fileName);
        std::string upper(std::string str);
        std::string lower(std::string str);
        // uint32_t getOperand1();
        // uint32_t getOperand2();
        // std::string getOPCODE();
};