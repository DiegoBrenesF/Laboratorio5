#include "double_list.h"

Lista* crearLista(){
       Lista* lista = (Lista*)malloc(sizeof(Lista));
       if (!lista){
          printf ("Error al asignar memoria para una nueva lista\n");
          exit(EXIT_FAILURE);
       }
       lista->cabeza = NULL;
       lista->cola = NULL;
       return lista;
}

Nodo* crearNodo(const char* dato){
      Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
      if (!nuevo){
         printf ("Error al asignar memoria para un nuevo nodo\n");
         exit(EXIT_FAILURE);
      }
      strcpy(nuevo->dato, dato);
      nuevo->siguiente = NULL;
      nuevo->anterior = NULL;
      return nuevo;
}

void insertarInicio(Lista* lista, const char* dato){
     Nodo* nuevo = crearNodo(dato);
     if (!lista->cabeza){
        lista->cabeza = lista->cola = nuevo;
     } else {
       nuevo->siguiente = lista->cabeza;
       lista->cabeza->anterior = nuevo;
       lista->cabeza = nuevo;
     }
     printf("El dato '%s' se ha insertado correctamente al inicio de la lista\n", dato);
}

void insertarFinal(Lista* lista, const char* dato){
     Nodo* nuevo = crearNodo(dato);
     if (!lista->cola){
        lista->cabeza = lista->cola = nuevo;
     } else {
       nuevo->anterior = lista->cola;
       lista->cola->siguiente = nuevo;
       lista->cola = nuevo;
     }
     printf("El dato '%s' se ha insertado correctamente al final de la lista\n", dato);
}

void insertarPorIndice(Lista* lista, const char* dato, int indice){
     if (indice < 1){
        printf ("La lista inicia en la posicion 1\n");
        printf ("No se puede inserta en la posicion %d\n", indice);
        return;
     }
     if (indice == 1){
        insertarInicio(lista, dato);
        return;
     }
     Nodo* actual = lista->cabeza;
     int posicion = 1;
     while (actual && posicion < indice-1){
           actual = actual->siguiente;
           posicion++;
     }

     if (!actual || actual->siguiente == NULL){
        printf ("La lista es de %d elementos\n", posicion);
        printf ("No se puede inserta en la posicion %d\n", indice);
        return;
     }
     Nodo* nuevo = crearNodo(dato);
     nuevo->siguiente = actual->siguiente;
     nuevo->anterior = actual;
     if (actual->siguiente){
        actual->siguiente->anterior = nuevo;
     }
     actual->siguiente = nuevo;
     if (!nuevo->siguiente){
        lista->cola = nuevo;
     }
     printf("El dato '%s' se ha insertado correctamente en la posicion [%d] de la lista\n", dato, indice);
}

void buscar(Lista* lista, const char* dato){
      Nodo* actual = lista->cabeza;
      int indice = 1;
      while (actual){
            if (strcmp(actual->dato, dato) == 0){
               printf("El dato '%s' se encuentra en la posicion [%d] de la lista\n", dato, indice);
               return;
            }
            actual = actual->siguiente;
            indice++;
      }
      printf("El dato '%s' no se encuentra en la lista\n", dato);
}

void eliminar(Lista* lista, const char* dato){
     Nodo* actual = lista->cabeza;
     while (actual){
           if (strcmp(actual->dato, dato) == 0){
              if (actual->anterior){
                 actual->anterior->siguiente = actual->siguiente;
              } else {
                lista->cabeza = actual->siguiente;
              }
              if (actual->siguiente){
                 actual->siguiente->anterior = actual->anterior;
              } else {
                lista->cola = actual->anterior;
              }
              free(actual);
              printf("El dato '%s' se ha eliminado correctamente", dato);
              return;
           }
           actual = actual->siguiente;
     }
     printf("El dato '%s' no se encuentra en la lista\n", dato);
}

void imprimirAdelante(Lista* lista){
     Nodo* actual = lista->cabeza;
     int indice = 1;
     printf("Lista de adelante hacia atras:\n");
     while (actual){
           printf("[%d]: %s\n", indice, actual->dato);
           actual = actual->siguiente;
           indice++;
     }
     if (indice == 1){
        printf("La lista esta vacia\n");
     }
}

void imprimirAtras(Lista* lista){
     Nodo* actual = lista->cola;
     int indice = 0;
     Nodo* temp = lista->cabeza;
     while (temp){
           indice++;
           temp = temp->siguiente;
     }
     if (indice == 0){
        printf("La lista esta vacia\n");
     }
     printf("Lista de atras hacia adelante:\n");
     while (actual){
           printf("[%d]: %s\n", indice, actual->dato);
           actual = actual->anterior;
           indice--;
     }
}

void destruirLista(Lista* lista){
     Nodo* actual = lista->cabeza;
     while (actual){
           Nodo* siguiente = actual->siguiente;
           free(actual);
           actual = siguiente;
     }
     free(lista);
}
