#include "lista.h"


// funcion que inserta un nodo nuevo en la lista
// entradas: el dato a guardar
// salidas: no tiene
void ListaSimple::insertar (Hijo * hijo)
{
     // si no hay elementos
     if (primerNodo == NULL)
     {
         // ambos apuntan al nuevo en memoria
         ultimoNodo = primerNodo = new NodoHijo(hijo);
     }
     else
     {
         NodoHijo *nuevo = new NodoHijo(hijo);
         nuevo->siguiente = primerNodo;
         primerNodo = nuevo; 
     }
}

// funcion que recorre toda la lista con pt tmp
// imprimiendo en consola cada dato de nodos
// entradas no tiene
// salidas: no tiene, solo imprime en consola
void ListaSimple::imprimir(void)
{
     NodoHijo *tmp = primerNodo;
     
     // mientras tmp no sea nulo, avanza
     while (tmp != NULL)
     {
           tmp->hijo->imprimir();
           tmp = tmp->siguiente;
     }
     cout << endl;
}
