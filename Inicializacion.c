 #include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "Constantes.h"


/********INICIALIZACION********/

void IniciaGpio(void)
{
    EALLOW;

	GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
	GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO

	// PUD J1								// 1 DESHABILITA, 0 HABILITA
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;		//Sentido 1A
	GpioCtrlRegs.GPAPUD.bit.GPIO23 = 1;		//Sentido 1B
	GpioCtrlRegs.GPAPUD.bit.GPIO19 = 1;		//IR 1
	GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1;		//IR 2
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;		//TX-C

	// PUD J2								// 1 DESHABILITA, 0 HABILITA  
	//GpioCtrlRegs.GPAPUD.bit.GPIO0  = 1;		//Motor-PWM 1
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // EPWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // EPWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;


	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 1;		//RX-C
	GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;		//LED 1

	// J1  									//1 SALIDA, 0 ENTRADA
	GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;		//Sentido 1A	PrincipalMotor2
	GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;		//Sentido 1B	PrincipalMotor2
	GpioCtrlRegs.GPADIR.bit.GPIO19 = 0;		//IR 1			PrincipalMotor2
	GpioCtrlRegs.GPADIR.bit.GPIO17 = 0;		//IR 2			PrincipalMotor2
	GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;		//TX-C			PrincipalMotor2
	// J2  
	GpioCtrlRegs.GPADIR.bit.GPIO0  = 1;		//Motor-PWM 1	PrincipalMotor2
	GpioCtrlRegs.GPADIR.bit.GPIO1  = 1;		//Motor-PWM
	GpioCtrlRegs.GPBDIR.bit.GPIO62 = 0;		//RX-C			PrincipalMotor2

	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;		//LED 1
	GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;

	GpioCtrlRegs.GPACTRL.all = 0x0000000;

	//EQEP
	GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP1A)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync to SYSCLKOUT GPIO20 (EQEP1A)
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;   // Configure GPIO20 as EQEP1A

  	EDIS;

  	 //Inicializacion de Puertos

  	 // J1
  	 GpioDataRegs.GPASET.bit.GPIO29 = 1;		// Sentido 1A	PrincipalMotor2
  	 GpioDataRegs.GPASET.bit.GPIO23 = 1;		// Sentido 1B	PrincipalMotor2
  	 GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1;		// TX-C
  	 // J2
  	 GpioDataRegs.GPACLEAR.bit.GPIO0  = 1;		// Motor-PWM 1

  	 GpioDataRegs.GPBSET.bit.GPIO34 = 1;		//LED 1



    return;
} //Fin IniciaGpio

void IniciaGpioEqep()
{
    EALLOW;

	GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP1A)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync to SYSCLKOUT GPIO20 (EQEP1A)
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;   // Configure GPIO20 as EQEP1A

  	EDIS;
    //return;
} //Fin IniciaGpioEqep

void HRPWM1_Config(period)
{
// ePWM1 register configuration with HRPWM
// ePWM1A toggle low/high with MEP control on Rising edge

	EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;	        // set Immediate load
	EPwm1Regs.TBPRD = 49999;// 99; //period-1;		                    // PWM frequency = 1 / period
	EPwm1Regs.CMPA.half.CMPA = 0; //period / 2;	            // set duty 50% initially
    //EPwm1Regs.CMPA.half.CMPAHR = (1 << 8);              // initialize HRPWM extension
	EPwm1Regs.CMPB = 10000;//period / 2;	                    // set duty 50% initially
	EPwm1Regs.TBPHS.all = 0;
	EPwm1Regs.TBCTR = 0;

	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;		       // EPWM1 is the Master
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.CLKDIV = 0x6;//TB_DIV4;

	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;

	EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;               // PWM toggle low/high
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm1Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
	EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;

/*
	EALLOW;
	EPwm1Regs.HRCNFG.all = 0x0;
	EPwm1Regs.HRCNFG.bit.EDGMODE = HR_REP;				//MEP control on Rising edge
	EPwm1Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm1Regs.HRCNFG.bit.HRLOAD  = HR_CTR_ZERO;
	EDIS;
*/

}

void HRPWM2_Config(period)
{
// ePWM2 register configuration with HRPWM
// ePWM2A toggle low/high with MEP control on Rising edge

	EPwm2Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;	        // set Immediate load
	EPwm2Regs.TBPRD = 99; //period-1;		                    // PWM frequency = 1 / period
	EPwm2Regs.CMPA.half.CMPA = 0xFF; //period / 2;	            // set duty 50% initially
    EPwm2Regs.CMPA.half.CMPAHR = (1 << 8);              // initialize HRPWM extension
	EPwm2Regs.CMPB = period / 2;	                    // set duty 50% initially
	EPwm2Regs.TBPHS.all = 0;
	EPwm2Regs.TBCTR = 0;

	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;		         // ePWM2 is the Master
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;

	EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;                  // PWM toggle low/high
	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm2Regs.AQCTLB.bit.ZRO = AQ_CLEAR;
	EPwm2Regs.AQCTLB.bit.CBU = AQ_SET;

	EALLOW;
	EPwm2Regs.HRCNFG.all = 0x0;
	EPwm2Regs.HRCNFG.bit.EDGMODE = HR_REP;                //MEP control on Rising edge
	EPwm2Regs.HRCNFG.bit.CTLMODE = HR_CMP;
	EPwm2Regs.HRCNFG.bit.HRLOAD  = HR_CTR_ZERO;

	EDIS;

}

void scic_fifo_init()
{
    ScicRegs.SCIFFTX.all=0xE040;
    ScicRegs.SCIFFRX.all=0x204f;
    ScicRegs.SCIFFCT.all=0x0;

}

void scic_echoback_init()
{
 	ScicRegs.SCICCR.all =0x0007;                                  
                                
	ScicRegs.SCICTL1.all =0x0003;  
	ScicRegs.SCICTL2.all =0x0003;
	ScicRegs.SCICTL2.bit.TXINTENA =1;
	ScicRegs.SCICTL2.bit.RXBKINTENA =1;
	#if (CPU_FRQ_150MHZ)
	      ScicRegs.SCIHBAUD    =0x0001;  //  9600 baudios @LSPCLK = 37.5MHz.
	      ScicRegs.SCILBAUD    =0x00E7;
	#endif
	#if (CPU_FRQ_100MHZ)
      ScicRegs.SCIHBAUD    =0x0001;  // 9600 baudios @LSPCLK = 20MHz.
      ScicRegs.SCILBAUD    =0x0044;
	#endif
	ScicRegs.SCICTL1.all =0x0023;  
}

//Fin inicializacion
