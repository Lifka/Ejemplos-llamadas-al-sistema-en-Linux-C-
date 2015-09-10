/*

********************************************

	Javier Izquierdo Vera
	javierizquierdovera@gmail.com
	UGR

********************************************

*/

// tarea11.c

#include <stdio.h>
#include <signal.h>

/*
Se suspende la ejecuci�n del proceso actual hasta que
reciba una se�al distinta de SIGUSR1
*/

int main(){
	// Creamos una nueva m�scara de se�ales
	sigset_t new_mask;

	/* inicializar la nueva mascara de se�ales */
	sigemptyset(&new_mask);

	// sigaddset=> A�ade una se�al a un conjunto de se�ales set previamente inicializado
	// A�adimos SIGUSR1 al conjunto de la m�scara
	sigaddset(&new_mask, SIGUSR1);

	// sigsuspend reemplaza temporalmente la m�scara de se�al para el proceso con la dada por el argumento mask y luego suspende el proceso hasta que se recibe una se�al.
	/*esperar a cualquier se�al excepto SIGUSR1 */
	sigsuspend(&new_mask);
}
