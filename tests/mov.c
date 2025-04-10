#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <microcvm/cpu.h>

void runTest(const char* filepath) {
    MicroCVMCPU cpu;
    initMicroCVMCPU(&cpu);

    if (loadBinary(&cpu, filepath) != 0) {
        printf("[FAIL] Could not load: %s\n", filepath);
        return;
    }

    while (1) {
        uint8_t opcode = cpu.memory[cpu.pc];
        if (opcode == hlt) break;

        executeInstruction(&cpu);
        cpu.pc++;
    }

    printf("[PASS] %-30s -> r0 = %d\n", filepath, cpu.registers[r0]);
}

int main() {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA("../../tests/bin/*.bin", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("No test binaries found.\n");
        return 1;
    }

    do {
        char filepath[MAX_PATH];
        snprintf(filepath, sizeof(filepath), "../../tests/bin/%s", findFileData.cFileName);
        runTest(filepath);
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
    return 0;
}