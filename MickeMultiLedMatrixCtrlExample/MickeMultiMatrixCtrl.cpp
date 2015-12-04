// 
// 
// 

#include "MickeMultiMatrixCtrl.h"

MickeMultiMatrixCtrl::MickeMultiMatrixCtrl(byte dataPin, byte clkPin, byte csPin, byte numOfMaxModules)
{
	//Store initiation values for later use
	_dataPin = dataPin;
	_clkPin = clkPin;
	_csPin = csPin;
	_numOfMaxModules = numOfMaxModules;
	
	//Initiate and setup control pins.
	pinMode(dataPin, OUTPUT);
	pinMode(clkPin, OUTPUT);
	pinMode(csPin, OUTPUT);

}

void MickeMultiMatrixCtrl::initLedModules(byte ledBrightness,bool runTest)
{
	
	//initiation of the max 7219
	allMaxModules(max7219_reg_scanLimit, 0x07);
	allMaxModules(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
	allMaxModules(max7219_reg_shutdown, 0x01);    // not in shutdown mode

	for (byte e = 1; e <= 8; e++)
	{    // empty registers, turn all LEDs off 
		allMaxModules(e, 0);
	}
	
	//Set initial brightness of all modules
	allMaxModules(max7219_reg_intensity, ledBrightness & 0x0f);    // the first 0x0f is the value you can set
												   // range: 0x00 to 0x0f
	//Run display test when initiated if it's specified
	if (runTest) displayTest();



}

void MickeMultiMatrixCtrl::setMatrixData(byte moduleIndex, byte column, byte rowData)
{
	_ledMatrixData[moduleIndex][column] = rowData;
}

void MickeMultiMatrixCtrl::displayMatrixData()
{
	byte col, maxIndex, dispCol;
	//Scan each row for data
	digitalWrite(_csPin, LOW);
	
	for (col = 0; col < 8; col++)
	{
		//Scan for values to be updated on each display
		for (maxIndex = 0; maxIndex < _numOfMaxModules; maxIndex++)
		{
			//Check if value is found
			if (_ledMatrixData[maxIndex][col] > 0)
			{
				//Data found. Send it to the Max modules
				dispCol = col + 1;
				putByte(dispCol);
				putByte(_ledMatrixData[maxIndex][col]);

				Serial.print(dispCol);
				Serial.print(" ");
				Serial.println(_ledMatrixData[maxIndex][col]);
			}
			else
			{
				//No data found send empty info.
				putByte(0);    // Do nothing
				putByte(0);    // Do nothing
			}
		}
		digitalWrite(_csPin, HIGH);
		digitalWrite(_csPin, LOW);
	}
}



void MickeMultiMatrixCtrl::allMaxModules(byte reg, byte col)
{    // initialize  all  MAX7219's in the system
	byte c = 0;
	digitalWrite(_csPin, LOW);  // begin     
	
	for (c = 1; c < _numOfMaxModules; c++)
	{
		putByte(reg);  // specify register
		putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
	}
	digitalWrite(_csPin, LOW);
	digitalWrite(_csPin, HIGH);
}

void MickeMultiMatrixCtrl::maxOne(byte maxNr, byte reg, byte col)
{
}

void MickeMultiMatrixCtrl::singleMaxModule(byte maxIndex, byte reg, byte col)
{
	//Old Single function
	//digitalWrite(_csPin, LOW);       // begin     
	//putByte(reg);                  // specify register
	//putByte(col);//((data & 0x01) * 256) + data >> 1); // put data   
	//digitalWrite(_csPin, LOW);       // and load da stuff
	//digitalWrite(_csPin, HIGH);

	int c = 0;
	digitalWrite(_csPin, LOW);  // begin     

	for (c = _numOfMaxModules; c > maxIndex + 1; c--)
	{
		putByte(0);    // means no operation
		putByte(0);    // means no operation
	}

	putByte(reg);  // specify register
	putByte(col);//((data & 0x01) * 256) + data >> 1); // put data 

	for (c = maxIndex; c >= 1; c--)
	{
		putByte(0);    // means no operation
		putByte(0);    // means no operation
	}

	digitalWrite(_csPin, LOW); // and load da stuff
	digitalWrite(_csPin, HIGH);

}

void MickeMultiMatrixCtrl::putByte(byte data)
{
	byte i = 8;
	byte mask;
	while (i > 0)
	{
		mask = 0x01 << (i - 1);      // get bitmask
		digitalWrite(_clkPin, LOW);   // tick
		if (data & mask)
		{            // choose bit
			digitalWrite(_dataPin, HIGH);// send 1
		}
		else
		{
			digitalWrite(_dataPin, LOW); // send 0
		}
		digitalWrite(_clkPin, HIGH);   // tock
		--i;                         // move to lesser bit
	}
}

void MickeMultiMatrixCtrl::displayTest()
{
	//Test lights up one module at a time
	for (byte i = 0; i < _numOfMaxModules; i++)
	{
		singleMaxModule(i, max7219_reg_displayTest,1);
		delay(200); //a delay so result is displayed
		singleMaxModule(i, max7219_reg_displayTest, 0);
	}

}

