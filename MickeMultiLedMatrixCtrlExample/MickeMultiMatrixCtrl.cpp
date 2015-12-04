// 
// 
// 

#include "MickeMultiMatrixCtrl.h"

MickeMultiMatrixCtrl::MickeMultiMatrixCtrl(int dataPin, int clkPin, int csPin, int numOfMaxModules)
{
	_numOfModules = numOfMaxModules;
	
	//Initiate and setup control pins.
	pinMode(dataPin, OUTPUT);
	pinMode(clkPin, OUTPUT);
	pinMode(csPin, OUTPUT);

}



