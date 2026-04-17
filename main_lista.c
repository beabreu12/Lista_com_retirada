#include <stdlib.h>
#include <stdio.h>
#include "mod_lista.h"

int main(){
    double remover_elem;
    Lista* l = lista_cria();

    l = lista_insere_ordenado(l, 12);
    l = lista_insere_ordenado(l, -2);
    l = lista_insere_ordenado(l, 25);
    l = lista_insere_ordenado(l, 37);
    l = lista_insere_ordenado(l, 5);
    
    printf("--- LISTA RESULTANTE ---\n");
    lista_imprime(l);

    printf("\n \n");
	system("pause");

    printf("\n DIGITE O ELEMENTO A SER REMOVIDO: ");
    scanf("%lf", &remover_elem);

    printf("\n Processando retirada...\n");
    printf("--- LISTA RESULTANTE ---\n");

    l = lista_retira(l, remover_elem);  // IMPORTANTE COLOCAR l = função PARA ATUALIZAR A LISTA

    lista_imprime(l);

    printf("\n \n");
	system("pause");

    return 0;
}

// gcc *.c -o programa.exe -lm    ou    gcc main.c mod_lista.c -o programa
//  .\programa.exe


    

        