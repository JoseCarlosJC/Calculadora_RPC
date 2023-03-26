#include "pila_char.h"
#include <stdlib.h>
#include <string.h>

struct pila_char crea_pila_char_vacia(){
   struct pila_char pila;
   pila.cadena = NULL;
   pila.tam = 0;
   pila.tam_max = 0;

   return pila;
}

//*****************************************************************************

struct pila_char crea_pila_char(size_t tam)
{
   struct pila_char pila;

   if (tam > 0){ 
      pila.cadena = (char *) malloc(tam * sizeof(char));
      pila.tam_max = tam;
      pila.tam = 0;

      return pila;
   }
   else
      return crea_pila_char_vacia();
}


void libera_pila_char(struct pila_char * pila)
{
   free(pila->cadena);
   *pila = crea_pila_char_vacia();
}


bool esta_vacia_pila_char(struct pila_char * pila)
{
   return pila->tam == 0;
}



char top_pila_char(struct pila_char * pila)
{
   return pila->cadena[(pila->tam)-1];
}


char pop_pila_char(struct pila_char * pila)
{
   char top = top_pila_char(pila);
   --(pila->tam);

   return top;
}

void push_pila_char(struct pila_char * pila, char elemento)
{
   if (pila->tam >= pila->tam_max){
      char * tmp = pila->cadena;
      size_t num_bytes = sizeof(char) * pila->tam;
      int nuevo_tam_max = pila->tam_max * 2;
      pila->cadena = (char *)malloc(nuevo_tam_max);
      pila->tam_max = nuevo_tam_max;

      memcpy(pila->cadena, tmp, num_bytes);
      free(tmp);
   }

   pila->cadena[pila->tam] = elemento;
   ++(pila->tam);
}



