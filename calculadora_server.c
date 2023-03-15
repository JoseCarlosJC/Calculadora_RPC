/**
 * Autor: José Carlos López Aguilar
 */

#include "calculadora.h"

double * suma_1_svc(double num1, double num2,  struct svc_req *rqstp)
{
	static double result;

	result = num1 + num2;

	return &result;
}
