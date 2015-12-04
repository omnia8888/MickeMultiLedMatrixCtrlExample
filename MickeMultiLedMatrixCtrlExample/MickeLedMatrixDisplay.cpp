// 
// 
// 

#include "MickeLedMatrixDisplay.h"


MickeLedMatrixDisplay::MickeLedMatrixDisplay(MickeMultiMatrixCtrl mmmCtrl)
	:MickeMultiMatrixCtrl(mmmCtrl)
{

}

void MickeLedMatrixDisplay::loadSunSymbolData()
{

	symbolDataStore = symbolSun;
	//Display symbol
	for (byte i = 0; i < 8; i++)
	{
		setMatrixData(1, i, symbolDataStore[i]);
	}
	displayMatrixData();
}



void MickeLedMatrixDisplay::loadSymbolData(byte symbolDigit)
{
	//Calculate start of symbol in ClockSymbols array.
	byte symStart = symbolDigit * SYMBOLS_CLOCK_SINGLE_MEM_SIZE;
	//load symbol data to storage
	for (byte i = 0; i < 7; i++)
	{
//		symbolDataStore[i] = ClockMatrixSymbols[i + symStart];

	}
}

void MickeLedMatrixDisplay::setSymbolFromStore()
{

}

