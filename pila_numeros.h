#include <stdlib.h>
#include <stdbool.h>

typedef double T; // Tipo de elementos que tendrá la pila

struct pila_numeros{
   T * num; // Donde se almacenan los números
   int tam; // Cantidad de elementos en la pila
   int tam_max; // Máxima cantidad posible de elementos en la pila
};


struct pila_numeros crea_pila_numeros(size_t tam);

void libera_pila_numeros(struct pila_numeros * pila);

bool esta_vacia_pila_numeros(struct pila_numeros * pila);

T top_pila_numeros(struct pila_numeros * pila);

T pop_pila_numeros(struct pila_numeros * pila);

void push_pila_numeros(struct pila_numeros * pila, T elemento);