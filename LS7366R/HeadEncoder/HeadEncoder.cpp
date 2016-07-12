// 
// 
// 

#include "HeadEncoder.h"
#include <SPI.h>
void HeadEncoderClass::init(EncoderAxis SelectInitAxis)
{
	if (SelectInitAxis == FocusCS)
	{
		
		pinMode(A9, OUTPUT);
		digitalWrite(A9, HIGH);
		SPI.begin(A9);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(X4_QUAD);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(FREE_RUN);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(DISABLE_IDX);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(ASYN_IDX);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(CLK_DIV_2);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(FOUR_BYTE);
		digitalWrite(A9, HIGH);


		digitalWrite(A9, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(ENABLE_CNT);
		digitalWrite(A9, HIGH);
	}

	if (SelectInitAxis == PanCS)
	{
	 
		pinMode(A8, OUTPUT);
		digitalWrite(A8, HIGH);
		SPI.begin(A8);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(X4_QUAD);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(FREE_RUN);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(DISABLE_IDX);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(ASYN_IDX);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(CLK_DIV_2);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(FOUR_BYTE);
		digitalWrite(A8, HIGH);


		digitalWrite(A8, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(ENABLE_CNT);
		digitalWrite(A8, HIGH);
	}


	if (SelectInitAxis == TiltCS)
	{
	
		pinMode(A10, OUTPUT);
		digitalWrite(A10, HIGH);
		SPI.begin(A10);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(X4_QUAD);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(FREE_RUN);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(DISABLE_IDX);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(ASYN_IDX);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR0);
		SPI.transfer(CLK_DIV_2);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(FOUR_BYTE);
		digitalWrite(A10, HIGH);


		digitalWrite(A10, LOW);
		SPI.transfer(WR_MDR1);
		SPI.transfer(ENABLE_CNT);
		digitalWrite(A10, HIGH);
	}

}

void HeadEncoderClass::Reset(EncoderAxis SelectResetAxis)
{
	if (SelectResetAxis == FocusCS)
	{
		digitalWrite(A9, LOW);
		SPI.transfer(WR_DTR);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		digitalWrite(A9, HIGH);

		digitalWrite(A9, LOW);
		SPI.transfer(LD_CNTR);
		digitalWrite(A9, HIGH);
	}
	if (SelectResetAxis ==TiltCS)
	{
		digitalWrite(A10, LOW);
		SPI.transfer(WR_DTR);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		digitalWrite(A10, HIGH);

		digitalWrite(A10, LOW);
		SPI.transfer(LD_CNTR);
		digitalWrite(A10, HIGH);
	}
	if (SelectResetAxis == PanCS)
	{
		digitalWrite(A8, LOW);
		SPI.transfer(WR_DTR);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		SPI.transfer(0x00);
		digitalWrite(A8, HIGH);

		digitalWrite(A8, LOW);
		SPI.transfer(LD_CNTR);
		digitalWrite(A8, HIGH);
	}
}
int32_t HeadEncoderClass::Read(EncoderAxis SelectReadAxis)
{
	if (SelectReadAxis == FocusCS)
	{
		int32_t count_value;
		int32_t count_1, count_2, count_3, count_4;
		digitalWrite(A9, LOW);
		SPI.transfer(RD_CNTR);
		count_1 = SPI.transfer(0x00);
		count_2 = SPI.transfer(0x00);
		count_3 = SPI.transfer(0x00);
		count_4 = SPI.transfer(0x00);
		digitalWrite(A9, HIGH);

		count_value = (count_1 << 24) + (count_2 << 16) + (count_3 << 8) + (count_4);

		return count_value;
	}
	if (SelectReadAxis == TiltCS)
	{
		int32_t count_value;
		int32_t count_1, count_2, count_3, count_4;
		digitalWrite(A10, LOW);
		SPI.transfer(RD_CNTR);
		count_1 = SPI.transfer(0x00);
		count_2 = SPI.transfer(0x00);
		count_3 = SPI.transfer(0x00);
		count_4 = SPI.transfer(0x00);
		digitalWrite(A10, HIGH);

		count_value = (count_1 << 24) + (count_2 << 16) + (count_3 << 8) + (count_4);

		return count_value;
	}
	if (SelectReadAxis == PanCS)
	{
		int32_t count_value;
		int32_t count_1, count_2, count_3, count_4;
		digitalWrite(A8, LOW);
		SPI.transfer(RD_CNTR);
		count_1 = SPI.transfer(0x00);
		count_2 = SPI.transfer(0x00);
		count_3 = SPI.transfer(0x00);
		count_4 = SPI.transfer(0x00);
		digitalWrite(A8, HIGH);

		count_value = (count_1 << 24) + (count_2 << 16) + (count_3 << 8) + (count_4);

		return count_value;
	}
}

HeadEncoderClass HeadEncoder;

