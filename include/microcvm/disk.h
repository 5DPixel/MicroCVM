#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define DISK_SIZE 32768 //32KB

typedef struct {
    uint8_t data[DISK_SIZE];
    const char* filepath;
} MicroCVMDisk;

void initMicroCVMDisk(MicroCVMDisk* disk);
void saveMicroCVMDisk(MicroCVMDisk* disk);
int writeToMicroCVMDisk(MicroCVMDisk* disk, uint16_t offset, const uint8_t* buffer, uint16_t size);
int readFromMicroCVMDisk(const MicroCVMDisk* disk, uint16_t offset, uint8_t* buffer, uint16_t size);