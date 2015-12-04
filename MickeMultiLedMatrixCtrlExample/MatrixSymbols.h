// MatrixSymbols.h

#ifndef _MATRIXSYMBOLS_h
#define _MATRIXSYMBOLS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ClockSymbols.h"

static byte* symbolData;

class MatrixSymbols
{
protected:


public:
	MatrixSymbols();

	void loadClockSymbolData(byte clockDigit);

	void loadSymbolData(byte symbolDigit);

private:
};

#endif

