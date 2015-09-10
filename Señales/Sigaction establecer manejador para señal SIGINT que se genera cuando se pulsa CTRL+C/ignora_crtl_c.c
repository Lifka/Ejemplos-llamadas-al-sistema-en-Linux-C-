/*

********************************************

	Javier Izquierdo Vera
	javierizquierdovera@gmail.com
	UGR

********************************************

*/

// tarea9.c 

#include <stdio.h>
#include <signal.h>

int main(){

	// Crea una variable sa de tipo sigaction
	struct sigaction sa;

	// Ignora la se�al
	sa.sa_handler = SIG_IGN;

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

	// Lo mantiene activo
	while(1);
}
