#include <hardware.h>


instruction_t fetch_decode(vm_hardware_t hw) {
    instruction_t ins;
    uint16_t instruction = hw.memory[hw.registers[R_PC]];
    ins.opcode = instruction >> 13;
    ins.operand[0] = 0b111 & (instruction >> 10);

    switch(ins.opcode) {
        case OPC_ADD:
        case OPC_NAND:
            ins.operand[1] = 0b111 & (instruction >> 7);
            ins.operand[2] = 0b111 & (instruction);
            break;
        case OPC_SW:
        case OPC_BEQ:
        case OPC_JALR:
        case OPC_ADDI:
            ins.operand[1] = 0b111 & (instruction >> 7);
            ins.operand[2] = (0b1111111) & instruction;
            break;
        case OPC_LUI:
            ins.operand[1] = ~(0b111111 << 10) & instruction;
            break;
    }
    return ins;
}

int init_machine(vm_hardware_t hw) {
    int i = 0;
    for(i = 0; i < MEMORY_SIZE; i++) {
        hw.memory[i] = 0;
    }
    for(i = 0; i < R_COUNT; i++) {
        hw.registers[i] = 0;
    }
    return 0;
}
