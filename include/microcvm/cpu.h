#pragma once

#include <stdio.h>
#include <stdint.h>

#define MEMORY_SIZE 32768 //32KB of memory

typedef struct {
    uint8_t memory[MEMORY_SIZE];
    uint16_t registers[8];
    uint16_t sp;
    uint16_t pc;
    uint8_t flags;
} MicroCVMCPU;

typedef enum {
    LOAD = 0x01,
    STORE = 0x02,
    ADD = 0x03,
    SUB = 0x04,
    JMP = 0x05,
    HLT = 0xFF,
    MOV = 0x06,
    INC = 0x07
} OpcodeType;

typedef enum {
    r0 = 0,
    r1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8
} Register;

void initMicroCVMCPU(MicroCVMCPU* cpu);
void executeInstruction(MicroCVMCPU* cpu);