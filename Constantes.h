#ifndef Constantes
#define Constantes

/*DEFINICION DE CONSTANTES*/

/* Definición de parámetros dependientes de la mecánica */
#define RADIO 4
#define PERIMETRO 3.14 * 2 * RADIO
#define RESOLUCION_ENCONDER 16
#define AVANCE_RUEDA PERIMETRO/RESOLUCION_ENCONDER


/* Registro del periodo para los PWMS */
#define PERIODO_PWM1  20
#define PERIODO_PWM2  50

#define TM_DEFINE_PARAMETROS 1
#define TM_CONFIRMA_CONECCION 3
#define CMD_GENSEN 5
#define TM_SENO 6
#define TM_MSG 7
#define TM_ERROR 8

#define CMD_HOME 128
#define CMD_RUN_CTRL 129
#define CMD_STOP_CTRL 130
#define CMD_PRUEBA_COM 131
#define CMD_CONECTA 132
#define CMD_SEL_CURSO 133
#define CMD_SALIR_CURSO 134
#define CMD_LED 135
#define CMD_DERECHA 136
#define CMD_IZQUIERDA 137
#define CMD_DETENTE 138

#define LENGTH_SENO 8

#define ID_GEN1 1

#endif

