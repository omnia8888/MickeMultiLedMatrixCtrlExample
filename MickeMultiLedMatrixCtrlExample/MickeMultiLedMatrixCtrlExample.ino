/*
 Name:		MickeMultiLedMatrixCtrlExample.ino
 Created:	12/4/2015 4:02:54 PM
 Author:	Micke
*/

#include "MickeLedMatrixDisplay.h"
#include "MickeMultiMatrixCtrl.h"


//Pin nummer konfigurationen som enheterna är
//inkopplade på
#define LEDCONTROL_DATA_PIN 12
#define LEDCONTROL_CLOCK_PIN 11
#define LEDCONTROL_CS_PIN 10

//Antal inkopplade MAX 7219 ledcontrol enheter
#define NUM_OF_LEDCONTROLS 2


void setup() {
	Serial.begin(9600);
	delay(1000);
	
	MickeMultiMatrixCtrl mMMC(12, 11, 10, 5);

	MickeLedMatrixDisplay mlmDisp(mMMC);

	mMMC.initLedModules(5,true);

	//mMMC.singleMaxModule(4,1, B00111100);

	//mMMC.setMatrixData(0, 0, B10000000);
	//mMMC.setMatrixData(1, 1, B11000000);
	/*mMMC.setMatrixData(2, 7, B11100000);

	mMMC.displayMatrixData();
*/
	mlmDisp.loadSunSymbolData();

	


}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
