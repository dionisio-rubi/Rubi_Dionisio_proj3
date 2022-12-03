#include "ARMInstruct.h"

// Initializes the registers to 0.
ARMInstruct::ARMInstruct(){
    registers["r0"] = 0;
    registers["r1"] = 0;
    registers["r2"] = 0;
    registers["r3"] = 0;
    registers["r4"] = 0;
    registers["r5"] = 0;
    registers["r6"] = 0;
    registers["r7"] = 0;
}

// MOV instruction - move immediate value into register
void ARMInstruct::movInstruct(std::string rd, uint32_t imm){
    registers[rd] = imm;
}

// add instruction: adds rn and rm and stores the result in rd
void ARMInstruct::addInstruct(std::string rd, std::string rn, std::string rm){
    registers[rd] = registers[rn] + registers[rm];
}

// sub intructions: subtractions rm from rn and stores the result in rd
void ARMInstruct::subInstruct(std::string rd, std::string rn, std::string rm){
    registers[rd] = registers[rn] - registers[rm];
}

// And Instruction of rn and rm and store the result in rd
void ARMInstruct::andInstruct(std::string rd, std::string rn, std::string rm){
    registers[rd] = registers[rn] & registers[rm];
}

// Orr Instruction of rn and rm and store the result in rd
void ARMInstruct::orrInstruct(std::string rd, std::string rn, std::string rm){
    registers[rd] = registers[rn] | registers[rm];
}

// Xor Instrction of rn and rm and store the result in rd
void ARMInstruct::xorInstruct(std::string rd, std::string rn, std::string rm){
    registers[rd] = registers[rn] ^ registers[rm];
}
 
// arithmetic shift right (asr)  of rn by n bits and store the result in rd
void ARMInstruct::asrInstruct(std::string rd, std::string rn, uint32_t n){
    int num = n;
    int32_t rn2 = registers[rn];
    registers[rd] = rn2 >> num;
}

// logical shift right (lsr) of rn by n bits and store the result in rd
void ARMInstruct::lsrInstruct(std::string rd, std::string rn, uint32_t n){
    int num = n;
    registers[rd] = registers[rn] >> num;
}

// logical left shift (lsl) of rn by n bits and store the result in rd
void ARMInstruct::lslInstruct(std::string rd, std::string rn, uint32_t n){
    int num = n;
    registers[rd] = registers[rn] << num;
}

// prints out all the registers with the result of the instructions
void ARMInstruct::getResult(){
    std::cout << "R0: 0x" << std::hex << registers["r0"] << "\t" << "R1: 0x" << std::hex << registers["r1"] << "\t" << "R2: 0x" << std::hex << registers["r2"] << "\t" << "R3: 0x" << std::hex << registers["r3"] << std::endl;
    std::cout << "R4: 0x" << std::hex << registers["r4"] << "\t" << "R5: 0x" << std::hex << registers["r5"] << "\t" << "R6: 0x" << std::hex << registers["r6"] << "\t" << "R7: 0x" << std::hex << registers["r7"] << std::endl;
}