#pragma once

typedef unsigned char reg8;
typedef unsigned short reg16;

/*
 As a consisent, compatible naming convention,
 uppercase register names are used as memoryaddrs
 and lowercase register names are used as values
*/
typedef enum
{
	NOP = 0x00,
	LDbc = 0x01,
	LDBCa = 0x02,
	INCbc = 0x03,
	INCb = 0x04,
	DECb = 0x05,
	LDb = 0x06,
	NOP7 = 0x07,
	NOP8 = 0x08,
	NOP9 = 0x09,
	NOPA = 0x0A,
	NOPB = 0x0B,
	INCc = 0x0C,
	DECc = 0x0D,
	LDc = 0x0E,
	NOPF = 0x0F,
} OpCode;

class CPU
{
public:
	CPU();

	void tick();

private:
	unsigned char memory[1024 * 32];
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

#pragma region OPS
	inline void LDbc(reg16 x)
	{
		b = x & 0xff;
		c = (x >> 8);
	}
	inline void LDBCa()
	{
		// load A into memaddr at BC
	}
	inline void INCb()
	{
		b++;
	}
	inline void DECb()
	{
		b--;
	}
	inline void LDb(reg8 x)
	{
		b = x;
	}

	inline void INCc()
	{
		c++;
	}
	inline void DECc()
	{
		c--;
	}
	inline void LDc(reg8 x)
	{
		c = x;
	}
#pragma endregion
};

