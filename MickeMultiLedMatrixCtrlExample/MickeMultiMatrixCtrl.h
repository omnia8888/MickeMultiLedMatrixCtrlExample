// MickeMultiMatrixCtrl.h

/*
The purpose for this library was intentially to remove dependency of LedControl library and
only focus on functionallity for Multiple Led Matrix Displays driven by Max7219 modules*/

/*Code History :

This code is inspired by an example orginaly found at:
http://playground.arduino.cc/LEDMatrix/Max7219
--------------

The original code was written for the Wiring board by :
*Nicholas Zambetti and Dave Mellis / Interaction Design Institute Ivrea / Dec 2004
* http ://www.potemkin.org/uploads/Wiring/MAX7219.txt

	First modifications by :
*Marcus Hannerstig / K3, malmö högskola / 2006
* http ://www.xlab.se | http://arduino.berlios.de
*tomek ness / FH - Potsdam / Feb 2007
* http ://design.fh-potsdam.de/


*/



#ifndef _MICKEMULTIMATRIXCTRL_h
#define _MICKEMULTIMATRIXCTRL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class MickeMultiMatrixCtrl
{
 protected:


 public:
	 MickeMultiMatrixCtrl(byte dataPin, byte clkPin, byte csPin, byte numOfMaxModules);

	 void initLedModules(byte ledBrightness = 5,bool runTest=false);

	 
	 void setMatrixData(byte moduleIndex,byte column,byte rowData);
	 
	 void displayMatrixData();

	void allMaxModules(byte reg, byte col);

	void maxOne(byte maxNr, byte reg, byte col);

	void singleMaxModule(byte maxIndex, byte reg, byte col);
	 

private:

	byte _dataPin, _clkPin, _csPin,_numOfMaxModules;
	
	void putByte(byte data);
	
	void displayTest();
	
	byte _ledMatrixData[8][8] = {};
	
	// define max7219 registers
	byte max7219_reg_noop = 0x00;
	byte max7219_reg_digit0 = 0x01;
	byte max7219_reg_digit1 = 0x02;
	byte max7219_reg_digit2 = 0x03;
	byte max7219_reg_digit3 = 0x04;
	byte max7219_reg_digit4 = 0x05;
	byte max7219_reg_digit5 = 0x06;
	byte max7219_reg_digit6 = 0x07;
	byte max7219_reg_digit7 = 0x08;
	byte max7219_reg_decodeMode = 0x09;
	byte max7219_reg_intensity = 0x0a;
	byte max7219_reg_scanLimit = 0x0b;
	byte max7219_reg_shutdown = 0x0c;
	byte max7219_reg_displayTest = 0x0f;
};



#endif

