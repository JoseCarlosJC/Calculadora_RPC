#include <stdlib.h>
#include <stdbool.h>

struct pila_char{
   char * cadena; // Donde se almacenan los caracteres
   int tam; // Cantidad de elementos en la pila
   int tam_max; // Máxima cantidad posible de elementos en la pila
};


struct pila_char crea_pila_char(size_t tam);

void libera_pila_char(struct pila_char * pila);

bool esta_vacia_pila_char(struct pila_char * pila);

char top_pila_char(struct pila_char * pila);

char pop_pila_char(struct pila_char * pila);

void push_pila_char(struct pila_char * pila, char elemento);