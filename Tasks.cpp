#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
//#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
//#include "Constantes.h"
#include "main_SO.h"
#include "DeclaraFun.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <Tasks.h>



void Task1(void) {
	int i = 0;
	for (;;)
	{
		GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;		//LED 1

		TiempoDelay = 1000;
		DELAY();

		GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;		//LED 1
		i++;

		TiempoDelay = 1000;
		DELAY();
	} //Termina for infinito de RutinaControl
} //Fin de RutinaControl

void Task2(void) {
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
