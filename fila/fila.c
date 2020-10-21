#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

fila *cria () {
    fila *f = (fila *)malloc(sizeof(fila));
    f->frente = NULL;
    f->fundo = NULL;
    return f;
}

int fila_vazia(fila *f) {
    return (f == NULL) || (f->frente == NULL);
}

// f = NULL
void inserir(fila *f, int v) {
    lista *novo = (lista *)malloc(sizeof(lista)); // novo = lista(8)
    novo->info = v;
    novo->prox = NULL;

    if (fila_vazia(f))
        f->frente = novo; // NULL->frente = novo
    else
        f->fundo->prox = novo; // lista(7)->prox = lista(8)  7->8->

    f->fundo = novo;     // f->fundo = lista(8)
}


void remover(fila *f ) {
    lista *aux ;
    if (fila_vazia(f)) {
        printf(" Fila vazia !\n");
        return;
    }

    aux = f->frente; // salvando temporariamente a frente da fila em aux
    f->frente = aux->prox; // a nova frente da fila eh o proximo da antiga frente

    if(f->frente == NULL)
        f->fundo = NULL;

    free(aux);
}


void imprime(fila * f) {
    if(fila_vazia(f)) {
        printf("fila vazia !\n");
        return;
    }

    for (lista *l = f->frente; l != NULL ; l = l->prox)
        printf ("%d ", l->info ) ;
    printf ("\n");
}

// nao podemos alterar o conteudo de uma variavel passada por parametro.
// so poderemos alterar se passarmos um ponteiro para a variavel passada por parametro.
// como a variavel ja era de um ponteiro, passamos um ponteiro duplo.
void libera(fila **f) {
    if (fila_vazia(* f))
        return;

    lista *l = (* f)->frente;
    while (l != NULL) {
        lista *aux = l->prox;
        free(l);
        l = aux;
    }
    free(* f);
    (* f) = NULL;
}
