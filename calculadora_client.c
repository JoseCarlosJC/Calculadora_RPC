/**
 * Autor: José Carlos López Aguilar
 * Template creado a partir de RPCGEN
 */

#include "calculadora.h"
#include <stdio.h>

#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define SALIR 5


calc_res calculadora_1(char *host, double num1, double num2, short operacion)
{
	CLIENT *clnt;
	calc_res * resultado;
	
#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, CALC_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	if (operacion == SUMAR){
		resultado = suma_1(num1, num2, clnt);
	}
	else if (operacion == RESTA){
		resultado = resta_1(num1, num2, clnt);
	}
	else if (operacion == MULTIPLICAR){
		resultado = multiplica_1(num1, num2, clnt);
	}
	else if (operacion == DIVIDIR){
		resultado = divide_1(num1, num2, clnt);
	}
	else{
		// OPERACION NO PERMITIDA
	}

	return (*resultado);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

// typedef enum {
// 	SUMAR = 1,
// 	RESTAR = 2,
// 	MULTIPLICAR = 3,
// 	DIVIDIR = 4,
// 	SALIR = 5
// } Opcion;


short menu_operacion(){
	short opcion;

	char * menu = 
	"OPERACIÓN\n\
	1)SUMAR\n\
	2)RESTAR\n\
	3)MULTIPLICAR\n\
	4)DIVIDIR\n\
	5)SALIR\n:";

	printf("%s", menu);
	scanf("%hi", &opcion);

	return opcion;
}


int main (int argc, char *argv[])
{
	char *host;
	short opcion;
	double num1, num2;
	calc_res resultado;
	// const int MAX_TAM = 255;
	// char * input[MAX_TAM];

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	do{
		opcion = menu_operacion();

		if (opcion != SALIR){
			printf("%s", "Números:");
			scanf("%lf %lf", &num1, &num2);
			//printf("%lf %lf", num1, num2);
			resultado = calculadora_1 (host, num1, num2, opcion);

			if (resultado.error == 1)
				printf("%s", "No se puede dividir por 0\n");
			else
				printf("Resultado: %lf\n", resultado.calc_res_u.resultado);
		}
	} while (opcion != SALIR);

	exit (0);
}
