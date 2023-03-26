#include "pila_numeros.h"
#include <stdlib.h>
#include <string.h>

struct pila_numeros crea_pila_numeros_vacia(){
   struct pila_numeros pila;
   pila.num = NULL;
   pila.tam = 0;
   pila.tam_max = 0;

   return pila;
}

//*****************************************************************************

struct pila_numeros crea_pila_numeros(size_t tam)
{
   struct pila_numeros pila;

   if (tam > 0){ 
      pila.num = (T *) malloc(tam * sizeof(T));
      pila.tam_max = tam;
      pila.tam = 0;

      return pila;
   }
   else
      return crea_pila_numeros_vacia();
}


void libera_pila_numeros(struct pila_numeros * pila)
{
   free(pila->num);
   *pila = crea_pila_numeros_vacia();
}


bool esta_vacia_pila_numeros(struct pila_numeros * pila)
{
   return pila->tam == 0;
}


T top_pila_numeros(struct pila_numeros * pila)
{
   return pila->num[(pila->tam)-1];
}


T pop_pila_numeros(struct pila_numeros * pila)
{
   T top = top_pila_numeros(pila);
   --(pila->tam);
   
   return top;
}

void push_pila_numeros(struct pila_numeros * pila, T elemento)
{
   if (pila->tam >= pila->tam_max){
      T * tmp = pila->num;
      size_t num_bytes = sizeof(T) * pila->tam;
      int nuevo_tam_max = pila->tam_max * 2;
      pila->num = (T *)malloc(nuevo_tam_max);
      pila->tam_max = nuevo_tam_max;

      memcpy(pila->num, tmp, num_bytes);
      free(tmp);
   }

   pila->num[pila->tam] = elemento;
   ++(pila->tam);
}



