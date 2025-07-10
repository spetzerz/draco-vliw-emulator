#pragma once
#include <limits.h>
#include "common.h"

#define PC_BITS 12 // 0 for default ( 16 bits )
#define LUT_AMOUNT 4

typedef struct instr_slot {
	byte Opcode, Dest, OPA, OPB;
} instr_slot_t;

typedef struct instruction {
	instr_slot_t slots[3];
} instruction_t;

typedef struct cpu {
	word registers[253];
	word memory[USHRT_MAX];
	word stack[USHRT_MAX];
	word callstack[USHRT_MAX];
	word output[16];
	word input[16];
	word lut_memory[LUT_AMOUNT][USHRT_MAX];

	word pc : PC_BITS ? PC_BITS : 16;
	word sp;
	word csp;
	instruction_t instruction;
} cpu_t;