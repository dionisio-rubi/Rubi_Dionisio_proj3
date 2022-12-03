#include <iostream>
#include <string>
#include <map>

class ARMInstruct{
    private:
        std::map<std::string, uint32_t> registers; // stores all the registers

    public:
        ARMInstruct();
        void movInstruct(std::string rd, uint32_t imm);
        void addInstruct(std::string rd, std::string rn, std::string rm);
        void subInstruct(std::string rd, std::string rn, std::string rm);
        void andInstruct(std::string rd, std::string rn, std::string rm);
        void orrInstruct(std::string rd, std::string rn, std::string rm);
        void xorInstruct(std::string rd, std::string rn, std::string rm);
        void asrInstruct(std::string rd, std::string rn, uint32_t n);
        void lsrInstruct(std::string rd, std::string rn, uint32_t n);
        void lslInstruct(std::string rd, std::string rn, uint32_t n);
        void getResult();
};