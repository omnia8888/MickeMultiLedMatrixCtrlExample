// MickeMultiMatrixCtrl.h

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
	 MickeMultiMatrixCtrl(int dataPin, int clkPin, int csPin, int numOfMaxModules);

private:
	byte _numOfModules;

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

