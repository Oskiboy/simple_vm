#ifndef HARDWARE_H
#define HARDWARE_H
#include <stdint.h>

#define MEMORY_SIZE     10000
#define PROG_MEM_END    1000
#define DATA_MEM        (MEMORY_SIZE - PROG_MEM_END)

enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_PC,
    R_LR,
    R_COND,
    R_COUNT
};

/*
 * Instruction formats:
 *
 * RRR - format
 *  | opcode    | reg A     | reg B     | 0         | reg C |
 *  | 3 bits    | 3 bits    | 3 bits    | 4 bots    | 3 bits|
 *
 * RRI - format
 *  | opcode    | reg A     | reg B     | Signed immediate  |
 *  | 3 bits    | 3 bits    | 3 bits    | 7bits             |
 *
 * RI - format
 *  | opcode    | reg A     |  Immediate                    |
 *  | 3 bits    | 3 bits    |  10 bits                      |
 *
 */
enum {
    OPC_ADD = 0,//Add                       - RRR OPC_ADDI,   //Add immediate             - RRI OPC_NADN,   //Nand                      - RRR
    OPC_LUI,    //Load Upper Immediate      - RI
    OPC_SW,     //Store Word                - RRI
    OPC_LW,     //Load Word                 - RRI
    OPC_BEQ,    //Branch if equal           - RRI
    OPC_JALR    //Jumpt and link register   - RRI
};

enum {
    FL_POS = 1 << 0,
    FL_ZRO = 1 << 1,
    FL_NEG = 1 << 2
};

#define INIT_MEMORY(_name)      static uint16_t _name[MEMORY_SIZE];
#define INIT_REGISTERS(_name)   static uint16_t _name[R_COUNT];

uint16_t read_mem(int address);
uint16_t write_mem(int address, uint16_t value);


#endif //HARDWARE_H

