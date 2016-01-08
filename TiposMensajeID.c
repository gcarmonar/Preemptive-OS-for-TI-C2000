void CargaParametros(char ID_rec){
	switch(ID_rec){
		case ID_CONTROL1:
			//Desempaco Flotantes
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				a1[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				b1[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				af1[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				bf1[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,1);
			c1 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			d1 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umax1 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umin1 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Ymax1 = rec_float[0];
		
			desempaca_float(paq_rec,1);
			Ymin1 = rec_float[0];
		
			//Desempaco Enteros
			desempaca_int(paq_rec,1);
			Tmax1 = rec_float[0];
	
			desempaca_int(paq_rec,1);
			Ts1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			Tfs1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex_min1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex_min1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			tex1 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			ref_type1 = rec_int[0];
			break;
		
		case ID_CONTROL2:
			//Desempaco Flotantes
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				a2[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				b2[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				a2f[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				b2f[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,1);
			c2 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			d2 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umax2 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umin2 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Ymax2 = rec_float[0];
		
			desempaca_float(paq_rec,1);
			Ymin2 = rec_float[0];
		
			//Desempaco Enteros
			desempaca_int(paq_rec,1);
			Tmax2 = rec_float[0];
	
			desempaca_int(paq_rec,1);
			Ts2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			Tfs2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex_min2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex_min2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			tex2 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			ref_type2 = rec_int[0];
			break;
			
		case ID_CONTROL3:
			//Desempaco Flotantes
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				a3[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				b3[i] = rec_float[i];
			}
	
			desempaca_float(paq_rec,5);
			for(i=0;i<5;i++){
				af3[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,6);
			for(i=0;i<6;i++){
				bf3[i] = rec_float[i];
			}
		
			desempaca_float(paq_rec,1);
			c3 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			d3 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umax3 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Umin3 = rec_float[i];
		
			desempaca_float(paq_rec,1);
			Ymax3 = rec_float[0];
		
			desempaca_float(paq_rec,1);
			Ymin3 = rec_float[0];
		
			//Desempaco Enteros
			desempaca_int(paq_rec,1);
			Tmax3 = rec_float[0];
	
			desempaca_int(paq_rec,1);
			Ts3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			Tfs3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fuex_min3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			fyex_min3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			tex3 = rec_int[0];
	
			desempaca_int(paq_rec,1);
			ref_type3 = rec_int[0];
			break;
			
		default:
			// Avisar que hubo error
			break;
	}
}


void PrendeLED(void){
	// Instrucciones para prender LED
	GpioDataRegs.GPACLEAR.bit.GPIO12 = 0;		// Solenoide 1
}//Fin de PrendeLED

void ApagaLED(void){
	// Instrucciones para apagar LED
	GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;		// Solenoide 1
}//Fin de ApagaLED

void CorreControl(void){
	switch(ID_rec){
	case ID_CONTROL1:
		Control1();
		break;
	case ID_CONTROL2:
			Control2();
			break;
	case ID_CONTROL1:
			Control3();
			break;
	default:
		// Avisar que hubo error
		break;
	}
	// Meter hilos de control a ACTIVOS
}//Fin de CorreControl

void Detener(void){
	// Poner controles a cero y sacar a CorreControl de ACTIVOS
}//Fin de Detener

void PruebaCom(void){
	// Rutina para probar comunicaciones
}//Fin de PruebaCom

void EnlazaPC(void){
	// Conectar a la PC del usuario
}//Fin de EnlazaPC

void SeleccionaCurso(char Seleccion){
	// Se pono en el Modo correspondiente según seleccione el usuario
}//Fin de SeleccionaCurso

void SalirCurso(void){
	// Manda a esperar selección del curso
}//Fin de SalirCurso

void GoHome(void){
	// Manda al carrito a la posición cero y lo detiene
}

void ErrorTM(void){
	// Avisa al usuario que hubo un error en TM
}
