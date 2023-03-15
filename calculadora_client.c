/**
 * Autor: José Carlos López Aguilar
 */

#include "calculadora.h"
#include <stdlib.h>
#include <stdio.h>


double calculadora_1(char *host, double suma_1_arg1, double suma_1_arg2)
{
	CLIENT *clnt;
	double  *result_1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, CALC_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = suma_1(suma_1_arg1, suma_1_arg2, clnt);
	if (result_1 == (double *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */

	return (*result_1);
}


int
main (int argc, char *argv[])
{
	char *host;
	double sum1, sum2;
	double suma;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	sum1 = atof(argv[2]);
	sum2 = atof(argv[3]);

	suma = calculadora_1 (host, sum1, sum2);

	printf("%f", suma);

	exit (0);
}
