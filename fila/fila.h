/**
 * Fila = FIFO
 */ 

// ESTRUTURAS
typedef struct lista { 
    int info ; 
    struct lista *prox ; 
} lista; 

typedef struct fila { 
    lista *frente; 
    lista *fundo; 
} fila; 

// ASSINATURAS DAS FUNCOES
fila *cria ();
int fila_vazia(fila * f); 
void inserir(fila *f , int v);
void remover(fila *f); 
void imprime(fila *f); 
void libera(fila ** f);
