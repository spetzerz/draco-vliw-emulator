#include "common.h"
#include "cpu.h"

#define DEST(slot) cpu.registers[cpu.instruction.slots[slot].Dest]
#define OPA(slot) cpu.registers[cpu.instruction.slots[slot].OPA]
#define OPB(slot) cpu.registers[cpu.instruction.slots[slot].OPB]

extern cpu_t cpu;

void nop()
{}

void add() 
{
	DEST(0) = OPA(0) + OPB(0);
}

void sub()
{
	DEST(0) = OPA(0) - OPB(0);
}

void mul()
{
	DEST(0) = OPA(0) * OPB(0);
}

void div()
{
	DEST(0) = OPA(0) / OPB(0);
}

void rem()
{
	DEST(0) = OPA(0) % OPB(0);
}

void and()
{
	DEST(0) = OPA(0) & OPB(0);
}

void or()
{
	DEST(0) = OPA(0) | OPB(0);
}

void xor()
{
	DEST(0) = OPA(0) ^ OPB(0);
}

void lut()
{
	DEST(0) = cpu.lut_memory[OPA(0)][OPB(0)];
}

void bsl()
{
	DEST(0) = OPA(0) << OPB(0);
}

void bsr()
{
	DEST(0) = OPA(0) >> OPB(0);
}

void load() 
{
	DEST(1) = cpu.memory[OPA(1) + OPB(1)];
}

void store()
{
	cpu.memory[OPA(1) + OPB(1)] = DEST(1);
}

void push() 
{
	cpu.stack[++cpu.sp] = OPA(1);
}

void pop()
{
	DEST(1) = cpu.stack[cpu.sp--];
}

void in()
{
	DEST(1) = cpu.input[OPA(1) + OPB(1)];
}

void out()
{
	cpu.output[OPA(1) + OPB(1)] = DEST(1);
}

void beq()
{
	if (OPA(2) == OPA(2))
		cpu.pc = DEST(2);
}

void bne()
{
	if (OPA(2) != OPA(2))
		cpu.pc = DEST(2);
}

void call()
{
	cpu.callstack[++cpu.csp] = cpu.pc;

	/* TODO
	OPA usage Not in offical docs, will add */
	cpu.pc = OPA(2);
}


void ret()
{
	cpu.pc = cpu.callstack[cpu.csp--];
}
