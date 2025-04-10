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

int getOpcodeArgumentCount(OpcodeType type){
    switch(type) {
        case inc: return 1;
        case mov: return 2;
        case add: return 2;
        case sub: return 2;
        default: return 0;
    }
}

Opcode createOpcode(MicroCVMCPU* cpu){
    Opcode currentInstruction = {0};
    uint8_t opcodeByte = cpu->memory[cpu->pc];

    currentInstruction.type = (OpcodeType)opcodeByte;
    currentInstruction.argumentCount = getOpcodeArgumentCount(currentInstruction.type);

    if (currentInstruction.argumentCount >= 1) {
        uint8_t arg1 = cpu->memory[cpu->pc + 1];
        if (arg1 < 8)
            currentInstruction.arg1.reg = (Register)arg1;
        else
            currentInstruction.arg1.address = (uint16_t)arg1;
    }

    if (currentInstruction.argumentCount >= 2) {
        uint8_t arg2 = cpu->memory[cpu->pc + 2];
        if (arg2 < 8)
            currentInstruction.arg2.reg = (Register)arg2;
        else
            currentInstruction.arg2.immediate = (int32_t)arg2;
    }

    return currentInstruction;
}

void executeInstruction(MicroCVMCPU* cpu){
    Opcode opcode = createOpcode(cpu);

    switch(opcode.type){
        case inc:
            cpu->registers[opcode.arg1.reg]++;
            break;

        case mov:
            cpu->registers[opcode.arg1.reg] = (uint16_t)opcode.arg2.immediate;
            break;

        case add:
            cpu->registers[opcode.arg1.reg] += (uint16_t)opcode.arg2.immediate;
            break;
        case sub:
            cpu->registers[opcode.arg1.reg] -= (uint16_t)opcode.arg2.immediate;
            break;
    }
}

int loadBinary(MicroCVMCPU* cpu, const char* filename){
    FILE* file;

    if(fopen_s(&file, filename, "rb") != 0){
        fprintf(stderr, "failed to open binary file!");
    }

    uint32_t bytesRead = (uint32_t)fread(cpu->memory, 1, MEMORY_SIZE, file);

    if (bytesRead > MEMORY_SIZE) {
        fprintf(stderr, "file size exceeds memory capacity.\n");
        fclose(file);
        return -1;
    }

    fclose(file);
    
    printf("Loaded %u bytes into memory.\n", bytesRead);
    return 0;
}