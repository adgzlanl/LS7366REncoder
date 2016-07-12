/*
LS7366R - Library for LS7366R IC Decoder .
Created by Anil Adiguzel / www.about.me/aniladiguzel , MAY 12, 2016.
Released into the public domain.
*/

#include "LS7366R.h"
#include "Arduino.h"
#include <SPI.h>



void LS7366R::SetStatusRegister(STRegister SelectStatusRegister) const

{
	SPI.transfer(SelectStatusRegister);
}


void LS7366R::OperationFunction(IRregister SelectOperation) const

{	
	SPI.transfer(SelectOperation);
}

void LS7366R::SetMDR0Register(MDR0Register SetMDR0bit) const

{	
	SPI.transfer(SetMDR0bit);
}

void LS7366R::SetMDR1Register(MDR1Register SetMDR1bit) const

{
	SPI.transfer(SetMDR1bit);
}


/*void LS7366R::InitAllRegisters(int SlaveSelect, IRregister SelectOperation, MDR0Register SetMDR0bit, MDR1Register SetMDR1bit, STRegister SelectStatusRegister) const
{


	
	digitalWrite(SlaveSelect, LOW);
	OperationFunction(SelectOperation);
	SetMDR0Register(SetMDR0bit);
	digitalWrite(SlaveSelect, HIGH);

	digitalWrite(SlaveSelect, LOW);
	OperationFunction(SelectOperation);
	SetMDR1Register(SetMDR1bit);
	digitalWrite(SlaveSelect, HIGH);

	digitalWrite(SlaveSelect, LOW);
	OperationFunction(SelectOperation);
	SetStatusRegister(SelectStatusRegister);
	digitalWrite(SlaveSelect, HIGH);




}
*/


