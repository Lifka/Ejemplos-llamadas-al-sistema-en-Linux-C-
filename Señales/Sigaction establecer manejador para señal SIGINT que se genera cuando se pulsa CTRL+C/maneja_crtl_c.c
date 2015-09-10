/*

********************************************

	Javier Izquierdo Vera
	javierizquierdovera@gmail.com
	UGR

********************************************

*/

// tarea10.c 

#include <stdio.h>
#include <signal.h>

static int s_recibida = 0;

static void handler (int signum){
	printf("\n Nueva acci�n del manejador \n");
	s_recibida++;
}

int main(){
	// Crea una variable sa de tipo sigaction
	struct sigaction sa;

	// Recibe la se�al en la funci�n establecida
	sa.sa_handler = handler;

	// Inicializa a vac�o el conjunto de se�ales
	sigemptyset(&sa.sa_mask); 

	//Reiniciar las funciones que hayan sido interrumpidas por un manejador 
	sa.sa_flags = SA_RESTART; 

	// signum => SIGINT -> Interrupci�n procedente del teclado (<Ctrl+C>) (P�gina 2 - Sesi�n 5)
	// act* => &sa -> nueva acci�n para la se�al signum se instala como act
	// oldact => NULL -> no se guarda la acci�n anterior
	if (sigaction(SIGINT, &sa, NULL) == -1){ // -1 -> error | 0 -> �xito
		printf("error en el manejador");
	}

	while(s_recibida < 3);
}

