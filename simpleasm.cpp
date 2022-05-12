#include <iostream>
#include <fstream>

enum Opcode {
  LDI, // 0000
  LDM, // 0001
  ST,  // 0010
  ADR, // 0011
  DIR, // 0100
  ADM, // 0101
  DIM, // 0110
  PCR, // 0111
  HALT // 1000
};

enum Register {
  R_OUT,  // 0000
  R_A,    // 0001
  R_B,    // 0010
  R_RE,   // 0011
  R_AR,   // 0100
  R_MO    // 0101
};

#define OPC(O) O << 4

const char program[256] = {
  OPC(LDM) | R_OUT, 15,
  OPC(LDM) | R_OUT, 16,
  OPC(LDM) | R_A, 16,
  OPC(LDM) | R_B, 15,
  OPC(ADM), 15,
  OPC(ADR) | R_B,
  OPC(ADM), 16,
  OPC(ADR) | R_A,
  
  OPC(PCR),

  1,
  1
};

int main(int argc, char *argv[]) {
  std::string fileName = "./out.bin";
  if(argc >= 2) {
    fileName = argv[1];
  }

  std::ofstream outfile(fileName, std::ofstream::binary | std::ofstream::out | std::ofstream::trunc);
  if(!outfile) {
    std::cerr << "Error opening " << fileName << std::endl;
  }

  outfile.write(program, 256);
  outfile.close();

}