#include <stdio.h>
#include <microcvm/cpu.h>

int main(){
    MicroCVMCPU cpu;
    initMicroCVMCPU(&cpu);

    loadBinary(&cpu, "../../tests/bin/mov.bin");

    while(1){
        uint8_t opcode = cpu.memory[cpu.pc];
        if(opcode == hlt) break;

        executeInstruction(&cpu);

        cpu.pc++;
    }

    printf("%d\n", cpu.registers[r0]);

    return 0;
}