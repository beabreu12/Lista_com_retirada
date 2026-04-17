#include <stdlib.h>
#include <stdio.h>
#include "mod_lista.h"

struct lista{
    double info;
    struct lista* proximo;
};

// FUNCAO PARA CRIAR A LISTA VAZIA
Lista* lista_cria(){
    return NULL;
};

// FUNCAO INSERE ELEMENTO
Lista* lista_insere_ordenado(Lista *l, double elem){

    Lista* novo;                // PONTERIRO PARA O NOVO ELEMENTO
    Lista* anterior = NULL;     // PONTEIRO PARA O ELEMENTO DA POSICAO ANTERIOR
    Lista* p = l;               // PONTEIRO AUXILIAR PARA PERCORRER A LISTA

    // PROCURA A POSICAO CORRETA DO ELEMENTO
    while(p != NULL && p->info < elem){
        anterior = p;       // SALVA O ELEMENTO DA LISTA QUE SERA ANTERIOR AO NOVO
        p = p->proximo;     // ATUALIZA O QUE APONTA PARA O PROXIMO
    }

    novo = (Lista*)malloc(sizeof(Lista));   // ALOCA MEMORIA PARA O NOVO ELEMENTO
    novo->info = elem;                      // SALVA A NOVA INFO

    if(novo == NULL){
        printf("\n MEMORIA NAO ALOCADA...");
        exit(1);
    }

    if(anterior == NULL){    // SE O ANTERIOR EH NULL, ENTAO ELE EH O PRIMEIRO
        novo->proximo = l;
        return novo;
    }else{              // MEIO DA LISTA
        novo->proximo = anterior->proximo;   
        anterior->proximo = novo;
        return l;
    }
};

// FUNCAO PARA IMPRIMIR A LISTA
void lista_imprime(Lista* l){

    Lista* p;
    
    for(p = l; p != NULL; p = p->proximo){
        printf("info: %.2f\n", p->info);
    }

};

// FUNCAO PARA VERIFICAR SE UM ELEMENTO ESTA NA LISTA
Lista* lista_busca(Lista* l, double elem){
    
    Lista* p;
    
    for(p = l; p != NULL; p = p->proximo){
        if( p->info == elem ){
            return p;
        }
    }
    return NULL;
};


// FUNCAO PARA LIBERAR A MEMORIA USADA PRA LISTA
void lista_libera(Lista* l){
    
    Lista* p = l;

    while(p != NULL){
        Lista* t = p->proximo;
        free(p);
        p = t;
    }
};

// FUNCAO PARA VERIFICAR SE A LISTA ESTA VAZIA
int lista_vazia(Lista* l) {
    return (l == NULL);
};

    
// FUNCAO PARA RETIRAR UM ELEMENTO DA LISTA
Lista* lista_retira (Lista* l, double elem){
    
    Lista* anterior = NULL;
    Lista* p = l;

    while(p != NULL && p->info != elem){
        anterior = p;       // ANTERIOR PASSA A SER O ULTIMO ANTES DO ELEMENTO DESEJADO
        p = p->proximo;     // p NA LISTA PASSA PARA QUEM O ELEMENTO DESEJADO APONTA
    }

    if (p == NULL){ // CHEGOU EM NULL, PERCORREU A LISTA E NAO ENCONTROU O ELEMENTO
        return l;
    }

    // RETIRANDO ELEMENTO A AJUSTO DO ENCADEAMENTO
    if (anterior == NULL){
        l = p->proximo; // CASO O ELEMENTO SEJA O PRIMEIRO
    }
    else{   
        anterior->proximo = p->proximo;
    }


    free(p);    // LIBERA O NÓ DO ELEMENTO DESEJADO
    return l;

};