#pragma once

typedef char reg8;
typedef short reg16;

typedef enum
{
	NOP = 00,
	NOP1 = 00,
	NOP2 = 00,
} OpCode;

class CPU
{
public:
	CPU();

	void tick();

	OpCode memory[1024 * 16];
	int interruptPeriod;
	int counter;

#pragma region Registers
	// Accumulator
	reg8 a;
	// Flags
	reg8 f;
	// General Purpose
	reg8 b;
	// General Purpose
	reg8 c;
	// General Purpose
	reg8 d;
	// General Purpose
	reg8 e;
	// General Purpose
	reg8 h;
	// General Purpose
	reg8 l;
	// Interrupt Register
	reg8 i;
	// Refresh Register
	reg8 r;
	// Index Register
	reg16 ix;
	// Index Register
	reg16 iy;
	// Stack Pointer
	reg16 sp;
	// Program Counter
	reg16 pc;
#pragma endregion
};

