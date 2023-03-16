/**
 * Autor: José Carlos López Aguilar
 * Template creado a partir de RPCGEN
 */
#include "calculadora.h"

double * suma_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 + arg2;

	return &result;
}

double * resta_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 - arg2;

	return &result;
}

double * multiplica_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = arg1 * arg2;

	return &result;
}

double * divide_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static double  result;

	result = 0;

	if (arg2 != 0){
		result = arg1 / arg2;
	}

	return &result;
}
