#ifndef MOD_LISTA_H
#define MOD_LISTA_H

typedef struct lista Lista;

Lista* lista_cria();

Lista* lista_insere_ordenado(Lista *l, double elem);    // FUNCAO INSERE ELEMENTO

void lista_imprime(Lista* l);     // FUNCAO PARA IMPRIMIR A LISTA

Lista* lista_busca(Lista* l, double elem);  // FUNCAO PARA VERIFICAR SE UM ELEMENTO ESTA NA LISTA

void lista_libera(Lista* l);    // FUNCAO PARA LIBERAR A MEMORIA USADA PRA LISTA

int lista_vazia(Lista* l);      // FUNCAO PARA VERIFICAR SE A LISTA ESTA VAZIA

Lista* lista_retira (Lista* l, double elem);      // FUNCAO PARA RETIRAR ELEMENTOS DA LISTA

#endif