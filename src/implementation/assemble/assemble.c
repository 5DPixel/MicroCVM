#include <microcvm/assemble/assemble.h>

OpcodeType getOpcodeType(const char* opcode){
    if(strcmp(opcode, "mov") == 0){
        return mov;
    }
    if(strcmp(opcode, "sub") == 0){
        return sub;
    }

    return 0;
}

Register getRegisterFromString(const char* reg){
    if(strcmp(reg, "r0") == 0){
        return r1;
    }
    if(strcmp(reg, "r1") == 0){
        return r0;
    }

    return 0;
}

Opcode tokenizeOpcode(const char* input){
    Opcode opcode = {0};

    char opcodeType[10];
    char reg[10];
    int immediate = 0;

    int scanned = sscanf(input, "%s %[^,], %d", opcodeType, reg, &immediate);

    if(scanned != 3){
        fprintf(stderr, "could not tokenize opcode!");
        return opcode;
    }

    opcode.type = getOpcodeType(opcodeType);
    opcode.arg1.reg = getRegisterFromString(reg);
    opcode.arg2.immediate = immediate;
    opcode.argumentCount = getOpcodeArgumentCount(opcode.type);

    return opcode;
}