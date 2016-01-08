/*
 * HilosTest.c
 *
 *  Created on: Dec 29, 2013
 *      Author: ross
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "FuncionesGlobales.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "HilosTest.h"

void FcnTask0(void);
void FcnTask1(void);
void FcnTask2(void);
void FcnTask3(void);


void FcnTask0(void) {
	Uint32 u32VarX = 1;
	Uint32 u32VarY = 1;
	Uint32 u32VarZ = 1;
	/* Prueba stack overflow */
	//Uint32 u32VarX1[10] = {0};
	//Uint32 u32VarY1[10] = {0};
	//Uint32 u32VarZ1 = 1;
	//Uint32 u32VarX2 = 1;
	//Uint32 u32VarY2 = 1;
	//Uint32 u32VarZ2 = 1;
	for (;;)
	{
		//for(;;)
		{
			u32VarX = u32VarX + 1;
			u32VarY = u32VarY + 1;
			u32VarZ = u32VarZ + 1;
			GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;		//LED 2
		}
		OS_SLEEP(304);
	} //Termina for infinito de Task2
}//Fin de Task2

void FcnTask1(void) {
	for (;;)
	{
		GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;		//LED 1
		OS_SLEEP(305);

	} //Termina for infinito de Task1
} //Fin de Task1

void FcnTask2(void) {
	for (;;)
	{
		//GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;		//LED 2
		OS_SLEEP(4000);
	} //Termina for infinito de Task2
}//Fin de Task2

void FcnTask3(void) {
	for (;;)
	{
		//GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;		//LED 1
		OS_SLEEP(4500);
	} //Termina for infinito de Task1
} //Fin de Task1



