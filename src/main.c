#include <stdio.h>
#include <microcvm/cpu.h>
#include <microcvm/disk.h>
#include <microcvm/assemble/assemble.h>

int main(){
    MicroCVMCPU cpu;
    MicroCVMDisk disk;
    disk.filepath = "../tests/disks/disk1.img";

    initMicroCVMCPU(&cpu);
    initMicroCVMDisk(&disk);

    loadBinary(&cpu, "../tests/bin/inc.bin");

    uint8_t sampleDiskData[] = { 0x68, 0x65, 0x6C, 0x6C, 0x6F };
    writeToMicroCVMDisk(&disk, 0, sampleDiskData, sizeof(sampleDiskData));

    saveMicroCVMDisk(&disk);

    while(1){
        uint8_t opcode = cpu.memory[cpu.pc];
        if(opcode == hlt) break;

        executeInstruction(&cpu);

        cpu.pc++;
    }

    printf("%d\n", cpu.registers[r0]);

    return 0;
}