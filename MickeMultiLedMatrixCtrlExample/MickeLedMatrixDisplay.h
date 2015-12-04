// MickeLedMatrixDisplay.h

#ifndef _MICKELEDMATRIXDISPLAY_h
#define _MICKELEDMATRIXDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MickeMultiMatrixCtrl.h"
#include "ClockSymbols.h"

static byte* symbolData;

class MickeLedMatrixDisplay:MickeMultiMatrixCtrl
{
 protected:


 public:
	 MickeLedMatrixDisplay(MickeMultiMatrixCtrl mmmCtrl);

	 void loadSymbolData(byte symbolDigit);
};



#endif

