/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_suma_1_argument (XDR *xdrs, suma_1_argument *objp)
{
	 if (!xdr_double (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}
