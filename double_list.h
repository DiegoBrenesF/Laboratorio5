#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
        char dato[25];
        struct Nodo* siguiente;
        struct Nodo* anterior;
}Nodo;

typedef struct Lista {
        Nodo* cabeza;
        Nodo* cola;
}Lista;

Lista* crearLista();
Nodo* crearNodo(const char* dato);
void insertarInicio(Lista* lista, const char* dato);
void insertarFinal(Lista* lista, const char* dato);
void insertarPorIndice(Lista* lista, const char* dato, int indice);
void buscar(Lista* lista, const char* dato);
void eliminar(Lista* lista, const char* dato);
void imprimirAdelante(Lista* lista);
void imprimirAtras(Lista* lista);
void destruirLista(Lista* lista);

#endif
