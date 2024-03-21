#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) 
{
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) 
{
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10. Recuerda que la lista almacena punteros, por lo que debes reservar memoria para cada elemento que agregues. Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
  List* lista = create_list();
  for(int i = 1; i <= 10; i++) {
    int* dato = (int*)malloc(sizeof(int));
    *dato = i;
    pushBack(lista, dato);
  }
  return lista;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y retorne la suma de sus elementos.
*/

int sumaLista(List *lista) 
{
  int suma = 0;
  int *dato;
  dato = (int*)first(lista);
  while(dato != NULL) {
    suma += *dato;
    dato = (int*)next(lista);
  }
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y un entero elem. La función debe eliminar todos los elementos de la lista que sean iguales a elem. Asume que popCurrent luego de eliminar un elemento se posiciona en el elemento anterior.
*/

void eliminaElementos(List *lista, int elem)
{
  int *dato = (int*)first(lista);
  while(dato != NULL) {
    if(*dato == elem) popCurrent(lista);
    dato = (int*)next(lista);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2. El orden de ambas pilas se debe mantener. Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack* PAux = create_stack();
  int *dato = (int*)first(P1);
  
  while(dato != NULL) {
    push(PAux, dato);
    dato = (int*)next(P1);
  }
  while((dato = pop(PAux)) != NULL) {
    push(P2, dato);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus paraéntesis balanceados. Retorna 1 si están balanceados, 0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
  Stack* pila = create_stack();
  for (int i = 0 ; cadena[i] != '\0' ; i++) {
    if (cadena[i] == '(' 
      || cadena[i] == '[' 
      || cadena[i] == '{') {
      push(pila, &cadena[i]);
    }
    else {
      char *ultimo = top(pila);
      if (ultimo == NULL) return 0;
      else if ((cadena[i] == ')' && *ultimo == '(')
        || (cadena[i] == ']' && *ultimo == '[')
        || (cadena[i] == '}' && *ultimo == '{')) {
        return 0;
      }
      else pop(pila);
    }
  }
  if (top(pila) != NULL) return 0;
  return 1;
}

