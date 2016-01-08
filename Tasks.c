#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "Tasks.h"
#include "DeclaraFun.h"

#include <stdio.h>
#include <string.h>



void Task1(void) {
	unsigned long int TiempoDelay;

	for (;;)
	{
		GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;		//LED 1

		TiempoDelay = 1000;
		DELAY();
	} //Termina for infinito de RutinaControl
} //Fin de RutinaControl

void Task2(void) {
	unsigned long int TiempoDelay;
	int var = 0;

	for (;;)
	{
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

		EPwm1Regs.CMPA.half.CMPA = var;
		var=var+1000;

		if (var>49999)
			var=0;

		TiempoDelay = 2000;
		DELAY();
	} //Termina for infinito de GetDato
}//Fin de GetDatos
