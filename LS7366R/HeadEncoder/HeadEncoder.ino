#include "HeadEncoder.h"

HeadEncoderClass PanEncoder;
HeadEncoderClass TiltEncoder;
HeadEncoderClass FocusEncoder;
void setup()
{
  Serial.begin(9600);

	PanEncoder.init(HeadEncoderClass::EncoderAxis::PanCS);
	TiltEncoder.init(HeadEncoderClass::EncoderAxis::TiltCS);
	FocusEncoder.init(HeadEncoderClass::EncoderAxis::FocusCS);
	PanEncoder.Reset(HeadEncoderClass::EncoderAxis::PanCS);
	TiltEncoder.Reset(HeadEncoderClass::EncoderAxis::TiltCS);
	FocusEncoder.Reset(HeadEncoderClass::EncoderAxis::FocusCS);
}

void loop()
{

	int32_t PanEncoderValue = PanEncoder.Read(HeadEncoderClass::EncoderAxis::PanCS);
	int32_t TiltEncoderValue = TiltEncoder.Read(HeadEncoderClass::EncoderAxis::TiltCS);
	int32_t FocusEncoderValue = FocusEncoder.Read(HeadEncoderClass::EncoderAxis::FocusCS);

	Serial.print(PanEncoderValue);
	Serial.print("-");
	Serial.print(TiltEncoderValue);
	Serial.print("-");
	Serial.println(FocusEncoderValue);
}
