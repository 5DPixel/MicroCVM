#pragma once

#include <microcvm/cpu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

OpcodeType getOpcodeType(const char* opcode);
Register getRegisterFromString(const char* reg);
Opcode tokenizeOpcode(const char* input);