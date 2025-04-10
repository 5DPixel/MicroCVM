#include <microcvm/disk.h>

void initMicroCVMDisk(MicroCVMDisk* disk){
    FILE *diskFile;
    if(fopen_s(&diskFile, disk->filepath, "wb") != 0){
        fprintf(stderr, "failed to open disk file: %s\n", disk->filepath);
        return;
    }

    memset(disk->data, 0, DISK_SIZE);
    
    fclose(diskFile);
}

void saveMicroCVMDisk(MicroCVMDisk* disk){
    FILE* diskFile;
    if (fopen_s(&diskFile, disk->filepath, "wb") != 0) {
        fprintf(stderr, "failed to save disk file: %s\n", disk->filepath);
        return;
    }

    fwrite(disk->data, 1, DISK_SIZE, diskFile);
    fclose(diskFile);
}

int writeToMicroCVMDisk(MicroCVMDisk* disk, uint16_t offset, const uint8_t* buffer, uint16_t size){
    if (offset + size > DISK_SIZE) {
        return 0;
    }
    memcpy(&disk->data[offset], buffer, size);
    return 1;
}

int readFromMicroCVMDisk(const MicroCVMDisk* disk, uint16_t offset, uint8_t* buffer, uint16_t size){
    if (offset + size > DISK_SIZE) {
        return 0;
    }
    memcpy(buffer, &disk->data[offset], size);
    return 1;
}