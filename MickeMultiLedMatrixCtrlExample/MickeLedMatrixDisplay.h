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


static byte *symbolDataStore;

class MickeLedMatrixDisplay:MickeMultiMatrixCtrl
{
 protected:


 public:
	 MickeLedMatrixDisplay(MickeMultiMatrixCtrl mmmCtrl);

	 void loadSunSymbolData();

	 void loadSymbolData(byte symbolDigit);

	 void setSymbolFromStore();

	 byte symbolSun[8] = {
		 B10010010,
		 B01010100,
		 B00111000,
		 B11111110,
		 B00111000,
		 B01010100,
		 B10010010,
		 B00000000
	 };
};



#endif

