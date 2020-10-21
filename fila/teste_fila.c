#include "fila.h"
#include <stdio.h>

int main(){
    fila *f = cria();

    inserir(f, 5);
    imprime(f); // 5

    inserir(f, 8);
    imprime(f); // 5 8

    remover(f);
    imprime(f); // 8

    inserir(f, 7);
    imprime(f); // 8 7

    libera(&f);

    if(fila_vazia(NULL))
        printf("Fila liberada!");

    return 0;
}