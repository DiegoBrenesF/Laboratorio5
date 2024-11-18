#include "double_list.h"

int main(){

    Lista* pruebaLista = crearLista();

    insertarInicio(pruebaLista, "mundo");
    insertarInicio(pruebaLista, "hola");
    insertarFinal(pruebaLista, "!");
    insertarFinal(pruebaLista, "!");
    insertarFinal(pruebaLista, "!");
    printf ("\n");
    imprimirAtras(pruebaLista);
    destruirLista(pruebaLista);

    return 0;
}

