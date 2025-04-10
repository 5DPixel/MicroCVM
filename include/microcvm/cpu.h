#pragma once

#include <stdio.h>
#include <stdint.h>

#define MEMORY_SIZE 32768 //32KB memory

typedef struct {
    uint8_t memory[MEMORY_SIZE];
    uint16_t registers[8];
    uint16_t sp;
    uint16_t pc;
    uint8_t flags;
} MicroCVMCPU;

typedef enum {
    load = 0x01,
    store = 0x02,
    add = 0x03,
    sub = 0x04,
    jmp = 0x05,
    hlt = 0xFF,
    mov = 0x06,
    inc = 0x07,
    _div = 0x08,
    mul = 0x09
} OpcodeType;

typedef enum {
    r0 = 0,
    r1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7
} Register;

typedef struct {
    OpcodeType type;
    int argumentCount;

    union {
        Register reg;
        uint16_t address;
    } arg1;

    union {
        Register reg;
        int32_t immediate;
        uint16_t address;
    } arg2;

} Opcode;

void initMicroCVMCPU(MicroCVMCPU* cpu);
int getOpcodeArgumentCount(OpcodeType type);
Opcode createOpcode(MicroCVMCPU* cpu);
void executeInstruction(MicroCVMCPU* cpu);
int loadBinary(MicroCVMCPU* cpu, const char* filename);
int storeOpcode(MicroCVMCPU* cpu, Opcode opcode);