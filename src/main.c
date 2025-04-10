#include <stdio.h>
#include <microcvm/cpu.h>

int main(){
    MicroCVMCPU cpu;
    initMicroCVMCPU(&cpu);

    cpu.memory[0] = INC;

    while(cpu.pc < MEMORY_SIZE){
        uint8_t opcode = cpu.memory[cpu.pc];

        executeInstruction(&cpu);

        cpu.pc++;
    }

    printf("%d\n", cpu.registers[r0]);

    return 0;
}