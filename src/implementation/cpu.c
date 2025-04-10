#include <microcvm/cpu.h>

void initMicroCVMCPU(MicroCVMCPU* cpu){
    for (int i = 0; i < MEMORY_SIZE; i++) {
        cpu->memory[i] = 0;
    }

    for (int i = 0; i < 8; i++) {
        cpu->registers[i] = 0;
    }

    cpu->sp = MEMORY_SIZE - 1;
    cpu->pc = 0;

    cpu->flags = 0;
}

void executeInstruction(MicroCVMCPU* cpu){
    unsigned char opcode = cpu->memory[cpu->pc];

    switch(opcode){
        case INC:
            cpu->registers[r0]++;
            break;
    }
}