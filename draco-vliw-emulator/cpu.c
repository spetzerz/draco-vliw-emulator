#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "cpu.h"

cpu_t cpu;

void UpdateIo()
{

}

void CpuTick()
{

}

int main() {
	while (TRUE) {
		UpdateIo();
		CpuTick();
	}
}
