// 
// 
// 

#include "MickeLedMatrixDisplay.h"

MickeLedMatrixDisplay::MickeLedMatrixDisplay(MickeMultiMatrixCtrl mmmCtrl)
	:MickeMultiMatrixCtrl(mmmCtrl)
{

}

void MickeLedMatrixDisplay::loadSymbolData(byte symbolDigit)
{
	//Calculate start of symbol in ClockSymbols array.
	byte symStart = clockDigit * SYMBOLS_CLOCK_SINGLE_MEM_SIZE;
	//load symbol data to storage
	for (byte i = 0; i < 7; i++)
	{
		symbolData[i] = ClockMatrixSymbols[i + symStart];

	}
}
