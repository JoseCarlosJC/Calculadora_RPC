/**
 * Autor: José Carlos López Aguilar
 * Template creado a partir de RPCGEN
 */
#include "calculadora.h"

calc_res * suma_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static calc_res  result;

	result.calc_res_u.resultado = arg1 + arg2;

	return &result;
}

calc_res * resta_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static calc_res  result;

	result.calc_res_u.resultado = arg1 - arg2;

	return &result;
}

calc_res * multiplica_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static calc_res  result;

	result.calc_res_u.resultado = arg1 * arg2;

	return &result;
}

calc_res * divide_1_svc(double arg1, double arg2,  struct svc_req *rqstp)
{
	static calc_res  result;

	result.calc_res_u.resultado = 0;

	if (arg2 == 0){
		result.error = 1; // División por 0
		return (&result);
	}

	result.calc_res_u.resultado = arg1 / arg2;
	return &result;
}
